import { useEffect, useState } from 'react';
import { ActivityIndicator, FlatList, Pressable, ScrollView, StyleSheet, Text, TextInput, View } from 'react-native';
import { Movie } from '../services/movie';
import MovieCard from '../services/movieCard';
import { fetchMovies } from '../services/tmdb_api';

const SearchBar = () => {
  const [search, setSearch] = useState('');
  const [movieList, setMovieList] = useState<Movie[] | null>(null);
  const [movieError, setMovieError] = useState<Error | null>(null);
  const [loading, setLoading] = useState(false);
  const [page, setPage] = useState(1);

  // можливість викликати з параметрами
  const loadMovies = async (q: string = search, p: number = page) => {
    try {
      setLoading(true);
      setMovieError(null);
      const list = await fetchMovies({ query: q, page: p });
      setMovieList(list);
    }
    catch (e: any) {
      if (e instanceof Error) setMovieError(e);
      setMovieList(null);
    }
    finally {
      setLoading(false);
    }
  }

  const loadMore = async () => {
    setPage(page + 1);
  }

  useEffect(() => { console.log(movieList); }, [movieList]);

  // автопошук при вводі
  useEffect(() => {
    const t = setTimeout(() => {
      const q = search.trim();
      if (q.length === 0) {
        setMovieList(null);
        return;
      }
      setPage(1);
      loadMovies(q, 1);
    }, 500);
    return () => clearTimeout(t);
  }, [search]);

  const renderContent = () => {
    if (loading) {
      return (
        <View>
          <ActivityIndicator size="large" color="#0000ff" />
          <Text>Loading...</Text>
        </View>
      );
    }
    if (movieError) {
      return (
        <View>
          <Text style={{ color: 'red' }}>Error: {movieError.message}</Text>
        </View>
      );
    }
    if (movieList) {
      return (
        <ScrollView>
          <View>
            <FlatList
              data={movieList}
              renderItem={({ item }) => (<MovieCard {...item} />)}
              keyExtractor={(item) => item.id.toString()}
              numColumns={2}
              onEndReachedThreshold={0.2}
              onEndReached={loadMore}
            >
            </FlatList>
          </View>
        </ScrollView>
      );
    }
    return null;
  };

  return (
    <View>
      <View style={styles.panel}>
        <TextInput
          style={styles.text}
          placeholder='Search'
          onChangeText={(value) => {
            setSearch(value);
            setPage(1);
          }}
          placeholderTextColor='#a6650bff'
        />
        <Pressable
          style={styles.button}
          onPress={() => {
            const q = search.trim();
            const next = page + 1;
            setPage(next);
            loadMovies(q, next);
          }}
        >
          <Text style={styles.buttonText}>Go</Text>
        </Pressable>
      </View>

      <View>
        {renderContent()}
      </View>
    </View>
  )
}

export default SearchBar

const styles = StyleSheet.create({
  panel: {
    flexDirection: 'row',
    padding: 5,
    height: 50,
    marginTop: 10,
    marginLeft: 10,
  },
  text: {
    color: 'yellow',
    fontWeight: 600,
    width: '75%',
    padding: 2,
    backgroundColor: '#102942ff',
    textAlign: 'auto',
  },
  button: {
    width: '23%',
    backgroundColor: '#a6650bff',
    color: 'maroon',
    padding: 2,
    borderRadius: 5,
    borderColor: '#102942ff',
    borderWidth: 1,
    margin: 2,
    marginRight: 10,
  },
  buttonText: {
    color: '#102942ff',
    fontWeight: 600,
    padding: 2,
    backgroundColor: '#a6650bff',
    textAlign: 'center',
  },
  item: {
    padding: 5,
    borderBottomWidth: 1,
    borderBottomColor: '#ccc',
    height: 200,
    width: '49%',
    marginBottom: 5,
  },
  title: {
    fontSize: 12,
    fontWeight: 'bold',
    color: '#c9b12aff',
  },
});
