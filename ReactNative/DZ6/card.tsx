import { Link } from 'expo-router'
import React from 'react'
import { Image, Pressable, StyleSheet, Text } from 'react-native'

type Picture = {
    id: number | string
    data: string
    tags?: string
    createdAt?: string
}

const card = ({ id, data, tags, createdAt }: Picture) => {

    return (
        <Link href={{ pathname: '/infoPicture', params: { id: String(id) } }} asChild >
            <Pressable style={styles.button} >
                <Image
                    source={{ uri: data }}
                    resizeMode='cover'
                    style={styles.image}
                />
                {tags && <Text style={styles.title} numberOfLines={1}>{tags}</Text>}
                {createdAt && <Text style={styles.text}>Date: {createdAt.split('-')[0]}</Text>}
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
        margin: 2
    },
    item: {
        height: 180,
        width: '90%'
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
