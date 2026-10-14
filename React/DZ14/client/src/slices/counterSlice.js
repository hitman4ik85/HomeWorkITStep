import { createSlice } from "@reduxjs/toolkit";

const initialValues = {
    value: 0
};

const counterSlice = createSlice({
    name: "counter", //даємо назву слайсу
    initialState: initialValues, //значення по замовчуванню
    reducers: { //методи стану та зміни значення
        increment: (state) => {
            state.value += 1;
        },
        decrement: (state) => {
            state.value -= 1;
        },
        amountBy:(state, action) => {
            state.value += action.payload;
        },
        reset: (state) => {
            state.value = 0;
        }
    }
});

export const { increment, decrement, amountBy, reset } = counterSlice.actions;
export default counterSlice.reducer;