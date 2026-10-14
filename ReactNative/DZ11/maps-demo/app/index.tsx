import { Markers } from "@/assets/markers";
import { useNavigation } from "expo-router";
import { useEffect, useRef, useState } from "react";
import { Pressable, StyleSheet, Text, TextInput, View } from "react-native";
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

  const manRef = useRef<MapView>(null);
  const navigation = useNavigation();

  useEffect(
    () => {
      navigation.setOptions({
        headerRight: () => (
          <Pressable onPress={focusMap}>
            <Text>Focus</Text>
          </Pressable>
        ),
      });
    },
    []);

  const focusMap = () => {
    const point = {
      latitude: lat,
      longitude: lng,
      latitudeDelta: 2,
      longitudeDelta: 2
    }
    //manRef.current?.animateToRegion(point);
    manRef.current?.animateCamera({ center: point, zoom: 15 }, { duration: 3000 });
  }

  const onRegionChange = (region: Region) => {
    setLat(region.latitude);
    setLng(region.longitude);
    //Alert.alert(`Region changed to\nLat: ${region.latitude}\nLng: ${region.longitude}`);
  }

  const onMarkerPress = (marker: any) => {
    alert(`Marker: ${marker}`);
  }

  return (
    <View style={styles.container}>
      <MapView style={styles.map}
        initialRegion={INIT_LOCATION}
        provider={PROVIDER_DEFAULT}
        showsMyLocationButton
        showsUserLocation
        ref={manRef}
        onRegionChangeComplete={onRegionChange}
      >
        {
          Markers.map((item, index) => (
            <Marker key={index} coordinate={item} onPress={() => { onMarkerPress(item.name) }}
            />
          ))
        }
        
        {
          // Новий маркер у точці завершення події onRegionChangeComplete
          (lat !== 0 || lng !== 0) && (
            <Marker coordinate={{ latitude: lat, longitude: lng }} />
          )
        }
      </MapView>
      <View style={styles.form}>
        <TextInput style={styles.input} placeholder="Latitude"
          value={lat.toString()} onChangeText={(text) => { setLat(Number(text)) }} />
        <TextInput style={styles.input} placeholder="Longitude"
          value={lng.toString()} onChangeText={(text) => { setLng(Number(text)) }} />
        <Pressable style={styles.button} onPress={focusMap}><Text>Go</Text></Pressable>
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: "center",
    alignItems: "center",
  },
  map: {
    width: '100%',
    height: '80%'
  },
  form: {
    width: '100%',
    height: '20%',
    backgroundColor: "#f0f0bfff",
    justifyContent: "center",
    alignItems: "center",
    flexDirection: "row",
    gap: 10
  },
  button: {
    backgroundColor: "#007bff",
    padding: 10,
    borderRadius: 5,
  },
  input: {
    height: 40,
    borderColor: 'gray',
    borderWidth: 1,
    paddingHorizontal: 10,
  }
});