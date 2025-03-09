const signUpButton = document.getElementById('signUp');
const signInButton = document.getElementById('signIn');
const container = document.getElementById('container');

signUpButton.addEventListener('click', () => {
	container.classList.add("right-panel-active");
});

signInButton.addEventListener('click', () => {
	container.classList.remove("right-panel-active");
});

// ✅ Firebase Authentication Setup
import { initializeApp } from "https://www.gstatic.com/firebasejs/11.4.0/firebase-app.js";
import { getAuth, signInWithEmailAndPassword, createUserWithEmailAndPassword, signInWithPopup, GoogleAuthProvider } from "https://www.gstatic.com/firebasejs/11.4.0/firebase-auth.js";

// ✅ Firebase Config
const firebaseConfig = {
            apiKey: "AIzaSyBQfXDpVpKRWUr6RTelKxcMeOFjSS6urw4",
        	authDomain: "cft-v2.firebaseapp.com",
        	databaseURL: "https://cft-v2-default-rtdb.firebaseio.com",
        	projectId: "cft-v2",
        	storageBucket: "cft-v2.firebasestorage.app",
        	messagingSenderId: "547160025326",
        	appId: "1:547160025326:web:d53a6a37a2e8a62226abff",
        	measurementId: "G-P399KTPNP2"
};

// ✅ Initialize Firebase
const app = initializeApp(firebaseConfig);
const auth = getAuth(app);
const provider = new GoogleAuthProvider();

// 🔹 Email/Password Sign-In
const signInBtn = document.querySelector(".sign-in-container button");
signInBtn.addEventListener("click", async (e) => {
    e.preventDefault();
    const email = document.querySelector(".sign-in-container input[type='email']").value;
    const password = document.querySelector(".sign-in-container input[type='password']").value;
    try {
        const userCredential = await signInWithEmailAndPassword(auth, email, password);
        alert("Login Successful! ✅");
        window.location.href = "Total.html"; // Redirect to Dashboard
    } catch (error) {
        alert(error.message);
    }
});

// 🔹 Email/Password Sign-Up
const signUpBtn = document.querySelector(".sign-up-container button");
signUpBtn.addEventListener("click", async (e) => {
    e.preventDefault();
    const email = document.querySelector(".sign-up-container input[type='email']").value;
    const password = document.querySelector(".sign-up-container input[type='password']").value;
    try {
        await createUserWithEmailAndPassword(auth, email, password);
        alert("Account Created Successfully! ✅");
    } catch (error) {
        alert(error.message);
    }
});

// 🔹 Google Sign-In
const googleBtn = document.querySelector(".social-container a.social");
googleBtn.addEventListener("click", async (e) => {
    e.preventDefault();
    try {
        const result = await signInWithPopup(auth, provider);
        alert("Google Sign-In Successful! ✅");
        window.location.href = "Total.html";
    } catch (error) {
        alert(error.message);
    }
});

