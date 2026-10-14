import { createSlice } from "@reduxjs/toolkit";
import { getPosts } from "../thunks/postsThunks";

const initialValues = {
  data: [],
  status: 'idle', // idle | loading | success | failed
  error: null
};

const postsSlice = createSlice({
  name: "posts",
  initialState: initialValues,
  extraReducers: (builder) => {
    builder
      .addCase(getPosts.pending, (state) => {
        state.status = 'loading';
      })
      .addCase(getPosts.fulfilled, (state, action) => {
        state.status = 'success';
        state.data = action.payload;
      })
      .addCase(getPosts.rejected, (state, action) => {
        state.status = 'failed';
        state.error = action.error.message;
      });
  }
});

export default postsSlice.reducer;
