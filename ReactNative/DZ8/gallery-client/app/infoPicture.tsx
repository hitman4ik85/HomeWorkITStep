import React, { useEffect, useState } from 'react'
import { Image, StyleSheet, Text, View } from 'react-native'
import { useLocalSearchParams } from 'expo-router'
import axios from 'axios'

interface PictureDetails {
    id: number
    tags: string
    data: string
    sentBy: string
    createdAt: string
}

const infoPicture = () => {

    const { Id } = useLocalSearchParams();
    const [item, setItem] = useState<PictureDetails | null>(null);
    const [error, setError] = useState<Error | null>(null);

    const loadDetails = async () => {
        try {
            setError(null);
            const url = `http://192.168.0.225:5104/api/pictures/${Id}`;

            // --- варіант через fetch --- для отримання деталей зображення
            // const responseFetch = await fetch(url, { method: 'GET' });
            // if (!responseFetch.ok) throw new Error(responseFetch.statusText);
            // const dataFetch = await responseFetch.json();
            // setItem(dataFetch);

            // --- актуальний варіант через axios --- для отримання деталей зображення
            const response = await axios.get(url, { method: 'GET' });
            if (response.status !== 200) throw new Error(response.statusText);
            setItem(response.data);
        } catch (error) {
            console.log(error);
            setError(error as Error);
            return null;
        }
    }

    useEffect(() => { loadDetails(); }, [Id]);

    return (
        <View style={styles.container}>
            {item ? (
                <>
                    <Image
                        source={{ uri: `data:image/jpeg;base64,${item.data}` }}
                        resizeMode='cover'
                        style={styles.image}
                    />
                    <Text style={styles.text}>Tags: {item.tags}</Text>
                    <Text style={styles.text}>by: {item.sentBy}</Text>
                    <Text style={styles.text}>at: {new Date(item.createdAt).toLocaleString()}</Text>
                </>
            ) : (
                <Text style={styles.text}>{error ? error.message : 'No data'}</Text>
            )}
        </View>
    )
}

export default infoPicture

const styles = StyleSheet.create({
    container: {
        flex: 1,
        backgroundColor: '#37597fff',
        alignItems: 'center',
        justifyContent: 'center',
        padding: 10
    },
    image: {
        width: '92%',
        height: '70%',
        margin: 2,
        borderRadius: 20
    },
    text: {
        marginTop: 10,
        marginBottom: 5,
        width: '92%',
        padding: 5,
        fontWeight: 600 as any,
        color: '#b0be0eff',
        fontSize: 16,
        textAlign: 'center'
    }
});
