import { Link } from 'expo-router'
import React from 'react'
import { Image, Pressable, StyleSheet, Text } from 'react-native'

export interface Picture {
    Id: number
    Tags: string
    Data: string
    SentBy: string
    CreatedAt: string
}

const card = ({ Id, Data, CreatedAt }: Picture) => {

    return (
        <Link
            href={{ pathname: '/infoPicture', params: { Id: String(Id) } }}
            asChild
        >
            <Pressable style={styles.button}>
                <Image
                    source={{ uri: `data:image/jpeg;base64,${Data}` }}
                    resizeMode='cover'
                    style={styles.image}
                />
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
        height: '75%',
        width: '90%',
        margin: 2,
        borderRadius: 8
    },
    text: {
        color: 'lightGrey',
        fontSize: 12,
        textAlign: 'left',
        marginTop: 4
    }
});
