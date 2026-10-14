import { useDispatch, useSelector } from 'react-redux';
import { decrement, increment, amountBy, reset } from './slices/counterSlice';

function Counter() {
  const counter = useSelector((state) => state.counter.value);
  const dispatch = useDispatch();

  return (
    <div>
      <button onClick={() => dispatch(decrement())}>-</button>
      {counter}
      <button onClick={() => dispatch(increment())}>+</button>
      <button onClick={() => dispatch(amountBy(5))}>+5</button>
      <br />
      <button onClick={() => dispatch(reset())}>reset</button>
    </div>
  );
}

export default Counter;
