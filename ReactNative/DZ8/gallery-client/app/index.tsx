import { useNavigation } from "@react-navigation/native";
import axios from "axios";
import React, { useEffect, useState } from "react";
import { ActivityIndicator, FlatList, StyleSheet, Text, View } from "react-native";
import Card, { Picture } from "../service/card";

const Index = () => {

  const [list, setList] = useState<Picture[] | null>(null);
  const [error, setError] = useState<Error | null>(null);
  const [loading, setLoading] = useState(false);

  const nav = useNavigation();

  const loadPictures = async () => {
    try {
      setLoading(true);
      setError(null);

      const url = 'http://192.168.0.225:5104/api/pictures';

      // --- варіант через fetch --- для отримання списку зображень
      // const responseFetch = await fetch(url, { method: 'GET' });
      // if (!responseFetch.ok) {
      //   throw new Error(`Failed to load pictures: ${responseFetch.statusText}`);
      // }
      // const dataFetch = await responseFetch.json();

      // --- актуальний варіант через axios --- для отримання списку зображень
      const response = await axios.get(url, { method: 'GET' });
      if (response.status !== 200) {
        throw new Error(`Failed to load pictures: ${response.statusText}`);
      }
      const data = response.data;

      const mapped: Picture[] = (data as any[]).map((x) => ({
        Id: x.id ?? x.Id,
        Tags: x.tags ?? x.Tags,
        Data: x.data ?? x.Data,
        SentBy: x.sentBy ?? x.SentBy,
        CreatedAt: x.createdAt ?? x.CreatedAt
      }));

      setList(mapped);
    }
    catch (error) {
      console.log(error);
      setError(error as Error);
      return null;
    }
    finally {
      setLoading(false);
    }
  }

  useEffect(() => { loadPictures(); }, []);

  // оновлюємо список ПРИ НАТИСКАННІ на кнопку(tabPress)
  useEffect(() => {
    const unsub = (nav as any).addListener('tabPress', () => {
      loadPictures();
    });
    return unsub;
  }, [nav]);

  const renderContent = () => {
    if (loading) {
      return (
        <View style={styles.center}>
          <ActivityIndicator size="large" />
          <Text style={styles.loadingText}>Loading...</Text>
        </View>
      );
    }
    if (error) {
      return (
        <View style={styles.center}>
          <Text style={styles.errorText}>Error: {error.message}</Text>
        </View>
      );
    }
    if (list && list.length > 0) {
      return (
        <View style={styles.listWrapper}>
          <Text style={styles.header}>
            All Images
          </Text>
          <FlatList
            data={list}
            renderItem={({ item }) => (<Card {...item} />)}
            keyExtractor={(item) => String(item.Id)}
            numColumns={2}
          />
        </View>
      );
    }
    return (
      <View style={styles.center}>
        <Text style={styles.emptyText}>No pictures yet</Text>
      </View>
    );
  };

  return (
    <View style={styles.container}>
      {renderContent()}
    </View>
  );
}

export default Index;

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#37597fff',
    alignItems: 'stretch',
    alignContent: 'flex-start',
    paddingTop: 20,
  },
  header: {
    color: '#c9b12aff',
    fontSize: 22,
    fontWeight: '600',
    marginBottom: 6,
    textAlign: 'center'
  },
  listWrapper: {
    paddingHorizontal: 4,
  },
  center: {
    alignItems: 'center',
    justifyContent: 'center',
    paddingTop: 40
  },
  loadingText: {
    color: '#c9b12aff',
    marginTop: 6
  },
  errorText: {
    color: 'red',
    fontWeight: '600'
  },
  emptyText: {
    color: '#c9b12aff'
  }
});
