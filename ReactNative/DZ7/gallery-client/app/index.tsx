import React, { useEffect, useState } from "react";
import { ActivityIndicator, FlatList, ScrollView, StyleSheet, Text, View } from "react-native";
import Card, { Picture } from "../service/card";

export default function Index() {

  const [list, setList] = useState<Picture[] | null>(null);
  const [error, setError] = useState<Error | null>(null);
  const [loading, setLoading] = useState(false);

  const loadPictures = async () => {
    try {
      setLoading(true);
      setError(null);

      const url = 'http://192.168.0.225:5104/api/pictures';
      const response = await fetch(url, { method: 'GET' });
      if (!response.ok) {
        throw new Error(`Failed to load pictures: ${response.statusText}`);
      }

      const data = await response.json();

      const mapped: Picture[] = (data as any[]).map((x) => ({
        Id: x.id ?? x.Id,
        Tags: x.tags ?? x.Tags,
        Data: x.data ?? x.Data,
        SentBy: x.sentBy ?? x.SentBy,
        CreatedAt: x.createdAt ?? x.CreatedAt
      }));

      setList(mapped);
    }
    catch (error: any) {
      if (error instanceof Error) setError(error);
      setList(null);
    }
    finally {
      setLoading(false);
    }
  }

  useEffect(() => { loadPictures(); }, []);

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
        <ScrollView>
          <View style={styles.listWrapper}>
            <FlatList
              data={list}
              renderItem={({ item }) => (<Card {...item} />)}
              keyExtractor={(item) => String(item.Id)}
              numColumns={2}
            />
          </View>
        </ScrollView>
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

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#37597fff',
    alignItems: 'stretch',
    alignContent: 'flex-start',
    paddingTop: 20,
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
