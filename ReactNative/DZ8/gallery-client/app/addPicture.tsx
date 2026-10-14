import axios from 'axios';
import * as Device from 'expo-device';
import * as ImagePicker from 'expo-image-picker';
import React, { useEffect, useState } from 'react';
import { Alert, Image, Pressable, StyleSheet, Text, TextInput, View } from 'react-native';
import { SelectList } from 'react-native-dropdown-select-list';

const addPicture = () => {

    const [file, setFile] = useState<string | null>(null);
    const [base64, setBase64] = useState<string | null>(null);
    const [tags, setTags] = useState<string>('');
    const [error, setError] = useState<string | null>(null);
    const [listTag, setListTag] = useState([]);
    const [selectedTag, setSelectedTag] = useState('');

    // Скидаємо форму на початкові значення
    const resetForm = () => {
        setFile(null);
        setBase64(null);
        setTags('');
        setSelectedTag('');
        setError(null);
    }

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

    // --- варіант через fetch --- для завантаження зображення
    // const uploadImage = async () => {
    //     if (!base64) return;
    //     if (!tags && !selectedTag) return;
    //     try {
    //         const url = 'http://192.168.0.225:5104/api/pictures';
    //         const response = await fetch(url, {
    //             method: 'POST',
    //             headers: {
    //                 'Content-Type': 'application/json',
    //             },
    //             body: JSON.stringify({
    //                 tags: `${tags ? tags : selectedTag}`,
    //                 data: `${base64}`,
    //                 sentby: `${Device.modelName ?? 'Unknown'}`,
    //                 createdat: new Date()
    //             }),
    //         });
    //         const data = await response.json();
    //         console.log('Success:', data);
    //         resetForm();
    //         Alert.alert('Success', 'Image uploaded.');
    //     } catch (error) {
    //         console.log(error);
    //         setError(error as string);
    //         return null;
    //     }
    // };

    // --- актуальний варіант через axios --- для завантаження зображення
    const uploadImage = async () => {
        if (!base64) return;
        if (!tags && !selectedTag) return;
        try {
            const url = 'http://192.168.0.225:5104/api/pictures';
            const toSend = {
                tags: `${tags ? tags : selectedTag}`,
                data: `${base64}`,
                sentby: `${Device.modelName ?? 'Unknown'}`,
                createdat: new Date()
            }
            const response = await axios.post(url, toSend, {
                headers: {
                    'Content-Type': 'application/json',
                },
            });
            console.log('Success:', response.data);
            resetForm(); // Скидаємо форму після успішного завантаження
            Alert.alert('Success', 'Image uploaded.');
        } catch (error) {
            console.log(error);
            setError(error as string);
            return null;
        }
    };

    // --- варіант через fetch --- для отримання списку тегів
    // const getTagList = async () => {
    //     const url = 'http://192.168.0.225:5104/api/pictures/tags';
    //     const response = await fetch(url, { method: 'GET' });
    //     if (response.ok) {
    //         const data = await response.json();
    //         console.log(data);
    //         const names = data.map((item: { tagName: string }) => item.tagName);
    //         setListTag(names);
    //     }
    //     else {
    //         console.log(response.statusText);
    //         setError(response.statusText);
    //         return null;
    //     }
    // };

    // --- актуальний варіант через axios --- для отримання списку тегів
    const getTagList = async () => {
        const url = 'http://192.168.0.225:5104/api/pictures/tags';
        const response = await axios.get(url, { method: 'GET' });
        if (response.status == 200) {
            const names = response.data.map((item: { tagName: string }) => item.tagName);
            setListTag(names);
        }
        else {
            console.log(response.statusText);
            setError(response.statusText as string);
            return null;
        }
    };

    useEffect(() => { uploadImage() }, [base64]);
    useEffect(() => { getTagList() }, []);

    return (
        <View style={styles.container}>
            <Text style={styles.header}>
                Add Image:
            </Text>
            <Pressable style={styles.button} onPress={pickImage}>
                <Text style={styles.buttonText}>Choose Image</Text>
            </Pressable>
            <View style={styles.form}>
                <TextInput onChangeText={(text) => { setTags(text) }} value={tags} placeholder="Enter tags" style={styles.input} />
                <SelectList
                    data={listTag}
                    search={false}
                    save="value"
                    setSelected={(item: string) => { setSelectedTag(item) }}
                />
                <Pressable style={styles.button} onPress={() => { imageToBase64() }}>
                    <Text style={styles.buttonText}>Upload Image</Text>
                </Pressable>
            </View>
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
        justifyContent: 'flex-start',
        alignItems: 'center',
        padding: 16,
        backgroundColor: '#37597fff'
    },
    header: {
        color: '#c9b12aff',
        fontSize: 22,
        fontWeight: '600',
        marginTop: 10,
        marginBottom: 6,
        textAlign: 'center'
    },
    button: {
        backgroundColor: '#a6650bff',
        paddingVertical: 10,
        paddingHorizontal: 12,
        borderRadius: 10,
        marginBottom: 14,
        marginTop: 10,
        borderWidth: 1,
        borderColor: '#102942ff',
        shadowColor: '#000000',
        shadowOffset: { width: 0, height: 2 },
        shadowOpacity: 0.25,
        shadowRadius: 6,
        elevation: 5
    },
    buttonText: {
        color: '#102942ff',
        fontSize: 16,
        fontWeight: '600',
        textAlign: 'center'
    },
    imageContainer: {
        width: '95%',
        borderRadius: 14,
        marginTop: 12,
        marginBottom: 16,
        backgroundColor: '#102942ff',
        padding: 10,
        alignItems: 'center',
        shadowColor: '#000000',
        shadowOffset: { width: 0, height: 2 },
        shadowOpacity: 0.25,
        shadowRadius: 6,
        elevation: 5
    },
    image: {
        width: 220,
        height: 220,
        borderRadius: 12
    },
    errorText: {
        color: 'red',
        marginTop: 16
    },
    form: {
        width: '95%',
        backgroundColor: '#c3d5e9ff',
        borderRadius: 12,
        borderWidth: 1,
        borderColor: 'silver',
        padding: 10
    },
    input: {
        borderRadius: 8,
        borderWidth: 1,
        borderColor: 'gold',
        backgroundColor: '#eef1f3ff',
        paddingVertical: 6,
        paddingHorizontal: 8,
        marginBottom: 8,
        color: '#102942ff'
    }
});
