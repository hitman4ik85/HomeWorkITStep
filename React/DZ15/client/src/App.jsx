import { Outlet } from "react-router";
import Header from "./components/Header/Header";
import { useEffect } from "react";
import { getAuthUser } from "./thunks/authThunk";
import { useDispatch, useSelector } from "react-redux";
import { getToken } from "./utils/token";
import Loader from "./components/Loader/Loader";

const App = () => {
  const dispatch = useDispatch();
  const auth = useSelector((state) => state.auth);

  useEffect(() => {
    if (getToken())
      dispatch(getAuthUser());
  }, [dispatch]);

  if (auth.status === "loading") return <Loader />;

  return (
    <div>
      <Header />
      <div style={{ padding: "0 40px" }}>
        <Outlet />
      </div>
    </div>
  );
};

export default App;
