import { configureStore } from '@reduxjs/toolkit';
import counterReducer from '../slices/counterSlice';
import articleReducer from '../slices/articleSlice';

const store = configureStore({
    reducer: {
        counter: counterReducer, //reducer countera
        articles: articleReducer //reducer article
    }
});

export default store;