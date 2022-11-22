import { StatusBar } from "expo-status-bar";
import { useEffect, useState } from "react";
import { StyleSheet, Text, View, FlatList } from "react-native";

export default function List() {
  const [data, setData] = useState("");

  const names = () => {
    fetch("https://jsonplaceholder.typicode.com/posts")
      .then((response) => response.json())
      .then((json) => setData(json));
  };
  useEffect (() => {
    names();
  },[])
  return (
    <View style={styles.container}>
        <Text>Lista</Text>
      <FlatList
        data={data}
        keyExtractor={item => item.id}
        renderItem={({ item }) => (
          <View style={styles.block}>
            <Text>{item.title}</Text>
          </View>
        )}
      />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "#fff",
    alignItems: "center",
    justifyContent: "center",
  },
  block: {
    padding:5,
    backgroundColor:"pink",
    borderWidth:2,
    borderRadius:5,
    borderColor:"white",
    marginHorizontal:20
  },
});
