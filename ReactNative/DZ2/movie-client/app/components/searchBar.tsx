import { Pressable, StyleSheet, Text, TextInput, View } from 'react-native'
import React from 'react'

const SearchBar = () => {
  return (
      <View>
        <View style={styles.panel}>
      <TextInput 
        style={styles.text} 
        placeholder='Search movie' 
        onChangeText={ (value) => {} }
        placeholderTextColor='white'
      />
      <Pressable style={styles.button} onPress={null}>
        <Text style={{ alignContent:'center' }}>Go</Text>
      </Pressable>
    </View>
    </View>
    
    
  )
}

export default SearchBar

const styles = StyleSheet.create({
    panel: {
        marginTop: 40,
        flexDirection: 'row',
        alignItems: 'stretch',
        padding: 5,
        height: 40,
    },
    text: {
        color: 'maroon',
        fontWeight: 600,
        width: '75%',
        padding: 2,
        backgroundColor: '#eae7aeff'
    },
    button: {
        width: '25%',
        backgroundColor: '#f5dbb0ff',
        color: 'maroon',
        padding: 2,
        borderRadius: 5,
        alignContent: 'center',
        borderWidth: 1,
        margin: 2,
        borderColor: 'maroon'
    },
})