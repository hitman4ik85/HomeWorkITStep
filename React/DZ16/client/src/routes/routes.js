import { createBrowserRouter } from "react-router";
import App from "../App";
import Articles from "../pages/Articles/Articles";
import CreateArticle from "../pages/Articles/CreateArticle";
import Article from "../pages/Articles/Article";
import Login from "../pages/Users/Login";
import Register from "../pages/Users/Register";
import AuthRoute from "./AuthRoute";
import Profile from "../pages/Users/Profile";
import EditArticle from "../pages/Articles/EditArticle";
import Users from "../pages/Users/Users";

const routes = createBrowserRouter([
  {
    path: '/',
    element: <App />,
    children: [
      { index: true, element: <Articles /> },
      { path: 'articles/:id', element: <Article /> },
      { path: 'articles/:id/edit', element: <AuthRoute><EditArticle /></AuthRoute> },
      { path: 'articles/create', element: <AuthRoute><CreateArticle /></AuthRoute> },
      { path: 'users', element: <AuthRoute><Users /></AuthRoute> },
      { path: 'profile', element: <AuthRoute><Profile /></AuthRoute> },
      { path: 'login', element: <Login /> },
      { path: 'register', element: <Register /> }
    ]
  }
]);

export default routes;
