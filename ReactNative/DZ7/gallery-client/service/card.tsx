import React from 'react'
import { Image, Pressable, StyleSheet, Text } from 'react-native'
import { Link } from 'expo-router'

export interface Picture {
    Id: number
    Tags: string
    Data: string
    SentBy: string
    CreatedAt: string
}

const card = ({ Id, Tags, Data, SentBy, CreatedAt }: Picture) => {

    return (
        <Link
            href={{ pathname: '/infoPicture', params: { Id: String(Id), Tags, SentBy, CreatedAt } }}
            asChild
        >
            <Pressable style={styles.button}>
                <Image
                    source={{ uri: `data:image/jpeg;base64,${Data}` }}
                    resizeMode='cover'
                    style={styles.image}
                />
                <Text style={styles.title} numberOfLines={1}>{Tags}</Text>
                <Text style={styles.text}>by: {SentBy}</Text>
                <Text style={styles.text}>at: {new Date(CreatedAt).toLocaleDateString()}</Text>
            </Pressable>
        </Link>
    )
}

export default card

const styles = StyleSheet.create({
    button: {
        backgroundColor: '#797523ff',
        padding: 10,
        borderRadius: 5,
        color: 'lightGreen',
        width: '50%',
        height: 160,
        margin: 2
    },
    image: {
        height: '60%',
        width: '90%',
        margin: 2,
        borderRadius: 8
    },
    title: {
        fontSize: 14,
        fontWeight: '600',
        color: 'lightGrey'
    },
    text: {
        color: 'lightGrey',
        fontSize: 10,
        textAlign: 'left'
    }
})
