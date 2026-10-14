import { createBrowserRouter } from 'react-router-dom';
import App from './App';
import ProductList from './components/shop/ProductList';
import Favorites from './pages/Favorites';
import Cart from './pages/Cart';

const router = createBrowserRouter([
  {
    path: '/',
    element: <App />,
    children: [
      {
        index: true,
        element: <ProductList />
      },
      {
        path: '/favorites',
        element: <Favorites />
      },
      {
        path: '/cart',
        element: <Cart />
      }
    ]
  }
]);

export default router;
