import { createBrowserRouter } from 'react-router';
import App from './App';
import ProductList from './components/shop/ProductList';
import Favorites from './pages/Favorites';
import Cart from './pages/Cart';
import Weather from './pages/Weather';
import NotFound from './pages/NotFound';

const router = createBrowserRouter([
  {
    path: '/',
    element: <App />,
    children: [
      { index: true, element: <ProductList /> },
      { path: '/favorites', element: <Favorites /> },
      { path: '/cart', element: <Cart /> },
      { path: '/weather', element: <Weather /> },
      { path: '*', element: <NotFound /> } // 404 як на парі
    ]
  }
]);

export default router;
