import { BrowserRouter, Routes, Route } from "react-router-dom";
import routes from "./routes";
import Header from "./components/Navbar";
import Footer from "./components/Footer";
import Sidebar from "./components/Sidebar";

function App() {
  return (
    <div className="font-body">
      <BrowserRouter>
        <div className="flex flex-row">
          <div className="flex flex-col">
            <Sidebar />
          </div>
          <div className="flex flex-col w-full">
            {/* <Header /> */}
            <Routes>
              {routes.map((route, index) => {
                return (
                  <Route
                    key={index}
                    path={route.path}
                    element={route.element}
                  />
                );
              })}
            </Routes>
            <Footer />
          </div>
        </div>
      </BrowserRouter>
    </div>
  );
}

export default App;
