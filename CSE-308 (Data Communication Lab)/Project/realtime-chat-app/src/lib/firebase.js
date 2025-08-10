import { initializeApp } from "firebase/app";
import { getAuth } from "firebase/auth";
import { getFirestore } from "firebase/firestore";
import { getStorage } from "firebase/storage";

const firebaseConfig = {
  apiKey: import.meta.env.VITE_API_KEY,
  authDomain: "realtimechatapp-f74ea.firebaseapp.com",
  projectId: "realtimechatapp-f74ea",
  storageBucket: "realtimechatapp-f74ea.appspot.com",
  messagingSenderId: "1041224584879",
  appId: "1:1041224584879:web:8c60eda0e8c5f46289ce5a",
};

const app = initializeApp(firebaseConfig);
export const auth = getAuth();
export const db = getFirestore();
export const storage = getStorage();
