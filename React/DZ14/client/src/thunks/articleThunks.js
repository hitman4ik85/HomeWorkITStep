import { createAsyncThunk } from "@reduxjs/toolkit";
import api from "../api/api";

export const getArticles = createAsyncThunk('articles/getArticles', async () => {
  const response = await api.get('articles');
  return response.data;
});

export const getArticle = createAsyncThunk('articles/getArticle', async (id) => {
  const response = await api.get(`articles/${id}`);
  return response.data;
});

export const createArticle = createAsyncThunk('articles/createArticle', async (article) => {
  const response = await api.post('articles', article);
  return response.data;
});
