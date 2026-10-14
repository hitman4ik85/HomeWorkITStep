import { Markers } from "@/assets/markers";
import { useNavigation } from "expo-router";
import { useEffect, useRef, useState } from "react";
import { KeyboardAvoidingView, Platform, Pressable, ScrollView, StyleSheet, Text, TextInput, View } from "react-native";
import MapView, { Marker, PROVIDER_DEFAULT, Region } from "react-native-maps";

const INIT_LOCATION = {
  latitude: 50.9077,
  longitude: 34.7981,
  latitudeDelta: 2,
  longitudeDelta: 2
};

export default function Index() {
  const [lat, setLat] = useState(0);
  const [lng, setLng] = useState(0);

  const [time, setTime] = useState<string[]>([]);
  const [temp, setTemp] = useState<number[]>([]);

  const manRef = useRef<MapView>(null);
  const navigation = useNavigation();

  // Focus — збільшує масштаб до координат із інпутів
  const focusInit = () => {
    const center = {
      latitude: (lat !== 0 ? lat : INIT_LOCATION.latitude),
      longitude: (lng !== 0 ? lng : INIT_LOCATION.longitude),
    };

    manRef.current?.animateCamera(
      { center, zoom: 15 },
      { duration: 3000 }
    );
  };

  useEffect(() => {
    navigation.setOptions({
      headerRight: () => (
        <Pressable onPress={focusInit} style={styles.headerBtn}>
          <Text style={styles.headerBtnText}>Focus</Text>
        </Pressable>
      ),
      headerTitle: "Maps Demo",
    });
  }, [lat, lng]);

  // Стартовий зум
  const onMapReady = () => {
    manRef.current?.animateCamera(
      {
        center: {
          latitude: INIT_LOCATION.latitude,
          longitude: INIT_LOCATION.longitude
        },
        zoom: 8
      },
      { duration: 1000 }
    );
  };

  // Go — на введені координати (або INIT_LOCATION, якщо нулі)
  const goToCoords = () => {
    const center = {
      latitude: lat || INIT_LOCATION.latitude,
      longitude: lng || INIT_LOCATION.longitude
    };

    manRef.current?.animateCamera({ center, zoom: 9 }, { duration: 1000 });
  };

  // https://api.open-meteo.com/v1/forecast?latitude=52.52&longitude=13.41&hourly=temperature_2m
  const onRegionChange = (region: Region) => {
    setLat(region.latitude);
    setLng(region.longitude);

    const url = `https://api.open-meteo.com/v1/forecast?latitude=${region.latitude}&longitude=${region.longitude}&hourly=temperature_2m`;
    fetch(url)
      .then((data) => data.json())
      .then((data) => {
        setTime(data.hourly.time);
        setTemp(data.hourly.temperature_2m);
      })
      .catch(err => console.log(err));
  };

  const onMarkerPress = (marker: any) => {
    alert(`Marker: ${marker}`);
  };

  return (
    <KeyboardAvoidingView
      style={styles.container}
      behavior={Platform.OS === "ios" ? "padding" : "height"}
      keyboardVerticalOffset={10}
    >
      <View style={styles.mapWrap}>
        <MapView
          style={styles.map}
          initialRegion={INIT_LOCATION}
          provider={PROVIDER_DEFAULT}
          showsMyLocationButton
          showsUserLocation
          ref={manRef}
          onRegionChangeComplete={onRegionChange}
          onMapReady={onMapReady}
        >
          {Markers.map((item, index) => (
            <Marker
              key={index}
              coordinate={item}
              onPress={() => { onMarkerPress(item.name) }}
            />
          ))}

          {(lat !== 0 || lng !== 0) && (
            <Marker coordinate={{ latitude: lat, longitude: lng }} />
          )}
        </MapView>
      </View>

      <View style={styles.form}>
        <Text style={styles.title}>Set location & weather</Text>

        <View style={styles.row}>
          <TextInput
            style={styles.input}
            placeholder="Latitude"
            placeholderTextColor="#94a3b8"
            value={lat.toString()}
            onChangeText={(text) => { setLat(Number(text)) }}
            keyboardType="numeric"
            inputMode="decimal"
            returnKeyType="done"
            submitBehavior="blurAndSubmit"
          />
          <TextInput
            style={styles.input}
            placeholder="Longitude"
            placeholderTextColor="#94a3b8"
            value={lng.toString()}
            onChangeText={(text) => { setLng(Number(text)) }}
            keyboardType="numeric"
            inputMode="decimal"
            returnKeyType="done"
            submitBehavior="blurAndSubmit"
          />
          <Pressable style={styles.button} onPress={goToCoords}>
            <Text style={styles.buttonText}>Go</Text>
          </Pressable>
        </View>

        <Text style={styles.subtitle}>Weather (°C)</Text>
        <ScrollView contentContainerStyle={styles.w_table}>
          {temp && time && temp.map((elem1, index) => {
            const elem2 = time[index];
            return (
              <View key={index} style={styles.w_cell}>
                <Text style={styles.w_time}>{elem2}</Text>
                <Text style={styles.w_temp}>{elem1}</Text>
              </View>
            );
          })}
        </ScrollView>
      </View>
    </KeyboardAvoidingView>
  );
}

const styles = StyleSheet.create({
  // загальний фон і відступи
  container: {
    flex: 1,
    backgroundColor: "#f1f5f9",
    paddingHorizontal: 12,
    paddingTop: 8,
    paddingBottom: 8,
  },

  // карта з заокругленням і рамкою
  mapWrap: {
    width: '100%',
    height: '60%',
    borderRadius: 12,
    overflow: 'hidden',
    borderWidth: 1,
    borderColor: '#e2e8f0',
    backgroundColor: '#ffffff',
  },
  map: {
    width: '100%',
    height: '100%',
  },

  // кнопка в хедері
  headerBtn: {
    marginRight: 10,
    paddingHorizontal: 10,
    paddingVertical: 6,
    backgroundColor: "#0ea5e9",
    borderRadius: 8,
  },
  headerBtnText: {
    color: "#ffffff",
    fontWeight: "600"
  },

  // нижня панель як «картка»
  form: {
    width: '100%',
    height: '40%',
    backgroundColor: "#ffffff",
    borderWidth: 1,
    borderColor: "#e2e8f0",
    borderRadius: 12,
    padding: 12,
    marginTop: 8,
    gap: 8
  },
  title: {
    fontSize: 16,
    fontWeight: "700",
    color: "#0f172a"
  },

  // рядок інпутів + кнопка
  row: {
    flexDirection: "row",
    alignItems: "center",
    gap: 8
  },
  input: {
    flex: 1,
    height: 44,
    borderColor: '#cbd5e1',
    borderWidth: 1,
    borderRadius: 8,
    paddingHorizontal: 10,
    backgroundColor: '#f8fafc',
    color: '#0f172a'
  },
  button: {
    paddingVertical: 12,
    paddingHorizontal: 14,
    backgroundColor: "#0ea5e9",
    borderRadius: 8,
    borderWidth: 1,
    borderColor: "#0284c7",
    alignItems: "center",
    justifyContent: "center"
  },
  buttonText: {
    color: "#ffffff",
    fontWeight: "700"
  },
  subtitle: {
    marginTop: 2,
    marginBottom: 4,
    fontSize: 14,
    fontWeight: "600",
    color: "#334155"
  },

  // плитки погоди
  w_table: {
    flexDirection: "row",
    flexWrap: "wrap",
    paddingBottom: 6
  },
  w_cell: {
    width: '48%',
    margin: '1%',
    borderColor: "#e2e8f0",
    borderWidth: 1,
    borderRadius: 10,
    backgroundColor: "#f8fafc",
    padding: 8,
    gap: 4
  },
  w_time: {
    fontSize: 12,
    color: "#64748b"
  },
  w_temp: {
    fontSize: 16,
    fontWeight: "700",
    color: "#0f172a"
  }
});
