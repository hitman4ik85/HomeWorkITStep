import { createSlice } from "@reduxjs/toolkit";
import { login } from "../thunks/authThunk";
import { setToken } from "../utils/token";

const initialState = {
    user: {},
    token: null,
    status: 'idle', // idle | loading | success | failed
    error: null
};

const authSlice = createSlice({
    name: "auth",
    initialState,
    reducers: {},
    extraReducers: (builder) => {
        builder
            .addCase(login.pending, (state) => {
                state.status = 'loading';
            })
            .addCase(login.fulfilled, (state, action) => {
                state.status = 'success';
                state.user = action.payload.user;
                state.token = action.payload.token;
                setToken(action.payload.token);
            })
            .addCase(login.rejected, (state, action) => {
                state.status = 'failed';
                state.error = action.error.message;
            });
    },
})

export default authSlice.reducer;