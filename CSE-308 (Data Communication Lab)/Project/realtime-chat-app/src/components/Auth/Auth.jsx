import { useState } from "react";
import { toast } from "react-toastify";
import "./Auth.css";
import {
  createUserWithEmailAndPassword,
  signInWithEmailAndPassword,
} from "firebase/auth";
import { doc, setDoc } from "firebase/firestore";
import { auth, db } from "../../lib/firebase";
import upload from "../../lib/upload";

const Auth = () => {
  const [isRegistered, setIsRegistered] = useState(true);
  const handleRegisterClick = () => {
    setIsRegistered(false);
  };

  const handleLoginClick = () => {
    setIsRegistered(true);
  };

  return (
    <div>
      {isRegistered ? (
        <Login onRegisterClick={handleRegisterClick} />
      ) : (
        <Register onLoginClick={handleLoginClick} />
      )}
    </div>
  );
};

function Login({ onRegisterClick }) {
  const [loading, setLoading] = useState(false);

  const handleLogin = async (e) => {
    e.preventDefault();
    setLoading(true);

    const formData = new FormData(e.target);
    const { email, password } = Object.fromEntries(formData);

    try {
      await signInWithEmailAndPassword(auth, email, password);
    } catch (err) {
      toast.error(err.message);
    } finally {
      setLoading(false);
    }

    e.target.reset();
  };
  return (
    <div className="login">
      <div className="item">
        <h2>Welcome back,</h2>
        <form onSubmit={handleLogin}>
          <input type="text" placeholder="Enter your email" name="email" />
          <input
            type="password"
            placeholder="Enter your password"
            name="password"
          />
          <button className="signIn" disabled={loading}>
            {loading ? "Loading..." : "Sign In"}
          </button>
          <p>
            Not registered yet?{" "}
            <button onClick={onRegisterClick}>Register</button>
          </p>
        </form>
      </div>
    </div>
  );
}

function Register({ onLoginClick }) {
  const [avatar, setAvatar] = useState({
    file: null,
    url: "",
  });

  const [loading, setLoading] = useState(false);
  const handleAvatar = (e) => {
    if (e.target.files[0]) {
      setAvatar({
        file: e.target.files[0],
        url: URL.createObjectURL(e.target.files[0]),
      });
    }
  };
  const handleRegister = async (e) => {
    e.preventDefault();
    setLoading(true);
    const formData = new FormData(e.target);
    const { username, email, password } = Object.fromEntries(formData);

    try {
      const res = await createUserWithEmailAndPassword(auth, email, password);

      const imgURL = await upload(avatar.file);

      await setDoc(doc(db, "users", res.user.uid), {
        id: res.user.uid,
        username,
        email,
        avatar: imgURL,
        blocked: [],
      });

      await setDoc(doc(db, "userChats", res.user.uid), {
        chats: [],
      });
      toast.success("User registered successfully");
    } catch (err) {
      toast.error(err.message);
    } finally {
      setLoading(false);
    }
    // e.target.reset();
  };
  return (
    <div className="login">
      <div className="item">
        <h2>Create an Account</h2>
        <form onSubmit={handleRegister}>
          <input
            type="text"
            placeholder="Enter your username"
            name="username"
          />
          <input type="text" placeholder="Enter your email" name="email" />
          <input
            type="password"
            placeholder="Enter your password"
            name="password"
          />
          <label htmlFor="file">
            <img src={avatar.url || "./avatar.png"} alt="" />
            Upload an image
          </label>
          <input
            type="file"
            name=""
            id="file"
            style={{ display: "none" }}
            onChange={handleAvatar}
          />
          <button className="signUp" disabled={loading}>
            {loading ? "Loading..." : "Sign Up"}
          </button>
          <p>
            Already registered? <button onClick={onLoginClick}>Login</button>
          </p>
        </form>
      </div>
    </div>
  );
}

export default Auth;
