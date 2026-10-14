import { Outlet } from "react-router";
import Header from "./components/Header";

const App = () => {
  return (
    <div>
      <Header />
      <div style={{padding: "0 40px"}}>
        <Outlet />
      </div>
    </div>
  );
};

export default App;
