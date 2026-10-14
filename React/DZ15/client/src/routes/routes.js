import { createBrowserRouter } from "react-router";
import App from "../App";
import Articles from "../pages/Articles";
import CreateArticle from "../pages/CreateArticle";
import Article from "../pages/Article";
import Login from "../pages/Login";
import Register from "../pages/Register";
import AuthRoute from "./AuthRoute";
import Profile from "../pages/Profile";

const routes = createBrowserRouter([
  {
    path: '/',
    element: <App />,
    children: [
      { index: true, element: <Articles /> },
      { path: 'articles/:id', element: <Article /> },
      { path: 'articles/create', element: <AuthRoute><CreateArticle /></AuthRoute> },
      { path: 'profile', element: <AuthRoute><Profile /></AuthRoute> },
      { path: 'login', element: <Login /> },
      { path: 'register', element: <Register /> }
    ]
  }
]);

export default routes;
