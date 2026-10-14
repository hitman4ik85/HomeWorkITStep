import * as ImagePicker from 'expo-image-picker';
import React, { useEffect, useState } from 'react';
import { Alert, Image, Pressable, StyleSheet, Text, TextInput, View } from 'react-native';

const addPicture = () => {

    const [file, setFile] = useState<string | null>(null);
    const [base64, setBase64] = useState<string | null>(null);
    const [tags, setTags] = useState<string>('');
    const [error, setError] = useState<string | null>(null);

    const pickImage = async () => {
        const { status } = await ImagePicker.requestMediaLibraryPermissionsAsync(); // Запит до камери пристрою Android
        //const { status: cameraStatus } = await ImagePicker.requestCameraPermissionsAsync(); // Запит до галереї пристрою IOS Iphone
        if (status !== 'granted') {
            Alert.alert('Permission Denied', 'You did not recived camera permission.');
        }
        else {
            const result = await ImagePicker.launchImageLibraryAsync({
                allowsEditing: true,
                aspect: [4, 3],
                quality: 1
            });

            // IOS Iphone Camera
            // const result = await ImagePicker.launchCameraAsync({
            //     allowsEditing: true,
            //     aspect: [4, 3],
            //     quality: 1
            // });

            if (!result.canceled) {
                setFile(result.assets[0].uri);
                setError(null);
            }
        }
    }

    const imageToBase64 = async () => {
        try {
            if (!file) return;
            fetch(file).
                then(response => response.arrayBuffer()).
                then(data => {
                    const b64 = btoa(new Uint8Array(data).reduce((item, byte) => item + String.fromCharCode(byte), ''));
                    setBase64(b64);
                });
        } catch (error) {
            console.log(error);
            setError(error as string);
            return null;
        }
    };

    const uploadImage = async () => {
        if (!base64) return;
        if (!tags) return;
        try {
            const url = 'http://192.168.0.225:5104/api/pictures';
            const response = await fetch(url, {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                },
                body: JSON.stringify({
                    tags: `${tags}`,
                    data: `${base64}`,
                    sentby: 'Author',
                    createdat: new Date()
                }),
            });
            const data = await response.json();
            console.log('Success:', data);
        } catch (error) {
            console.log(error);
            setError(error as string);
            return null;
        }
    };

    useEffect(() => { uploadImage() }, [base64]);

    return (
        <View style={styles.container}>
            <Text style={styles.header}>
                Add Image:
            </Text>
            <Pressable style={styles.button} onPress={pickImage}>
                <Text style={styles.buttonText}>Choose Image</Text>
            </Pressable>
            <TextInput onChangeText={(text) => { setTags(text) }} value={tags} placeholder="Enter tags" />
            <Pressable style={styles.button} onPress={() => { imageToBase64() }}>
                <Text style={styles.buttonText}>Upload Image</Text>
            </Pressable>

            {file ? (
                <View style={styles.imageContainer}>
                    <Image source={{ uri: file }} style={styles.image} />
                </View>
            ) : (
                <Text style={styles.errorText}>{error}</Text>
            )}
        </View>
    );
}

export default addPicture

const styles = StyleSheet.create({
    container: {
        flex: 1,
        justifyContent: "center",
        alignItems: "center",
        padding: 16,
    },
    header: {
        fontSize: 20,
        marginBottom: 16,
    },
    button: {
        backgroundColor: "#007AFF",
        padding: 10,
        borderRadius: 8,
        marginBottom: 16,
        shadowColor: "#000000",
        shadowOffset: { width: 0, height: 2 },
        shadowOpacity: 0.4,
        shadowRadius: 4,
        elevation: 5,
    },
    buttonText: {
        color: "#FFFFFF",
        fontSize: 16,
        fontWeight: "bold",
    },
    imageContainer: {
        borderRadius: 8,
        marginBottom: 16,
        shadowColor: "#000000",
        shadowOffset: { width: 0, height: 2 },
        shadowOpacity: 0.4,
        shadowRadius: 4,
        elevation: 5,
    },
    image: {
        width: 200,
        height: 200,
        borderRadius: 8,
    },
    errorText: {
        color: "red",
        marginTop: 16,
    },
});