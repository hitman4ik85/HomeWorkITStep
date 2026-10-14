import { createAsyncThunk } from "@reduxjs/toolkit";
import axios from "axios";

// createAsyncThunk -> axios -> return response.data
export const getPosts = createAsyncThunk('posts/getPosts', async () => {
  const response = await axios.get('https://jsonplaceholder.typicode.com/posts');
  return response.data; // [{id, title, body}, ...]
});
