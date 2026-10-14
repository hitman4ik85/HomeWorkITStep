import { Outlet } from 'react-router-dom';
import Header from './pages/templates/Header';

function App() {
  return (
    <div>
      <Header />
      <Outlet />
    </div>
  );
}

export default App;
