import "./Details.css";
import { auth, db } from "../../lib/firebase";
import { doc, updateDoc, arrayRemove, arrayUnion } from "firebase/firestore";
import { useChatStore } from "../../lib/chatStore";
import { useUserStore } from "../../lib/userStore";

const Details = () => {
  const {
    chatId,
    user,
    isCurrentUserBlocked,
    isReceiverBlocked,
    changeBlock,
    resetChat,
  } = useChatStore();
  const { currentUser } = useUserStore();

  const handleBlock = async () => {
    if (!user) return;

    const userDocRef = doc(db, "users", currentUser.id);

    try {
      await updateDoc(userDocRef, {
        blocked: isReceiverBlocked ? arrayRemove(user.id) : arrayUnion(user.id),
      });
      changeBlock();
    } catch (err) {
      console.log(err);
    }
  };

  const handleLogout = () => {
    auth.signOut();
    resetChat();
  };

  return (
    <div className="details">
      <div className="user">
        <img src={user?.avatar || "./avatar.png"} alt="" />
        <h2>{user?.username}</h2>
        <p>Lorem ipsum dolor sit amet</p>
      </div>
      <div className="info">
        <div className="option">
          <div className="title">
            <span>Chat Settings</span>
            <img src="./arrowUp.png" alt="" />
          </div>
        </div>
        <div className="option">
          <div className="title">
            <span>Privacy & help</span>
            <img src="./arrowUp.png" alt="" />
          </div>
        </div>
        <div className="option">
          <div className="title">
            <span>Shared photos</span>
            <img src="./arrowDown.png" alt="" />
          </div>
          <div className="photos">
            <div className="photoItem">
              <div className="photoDetails">
                <img
                  src="https://static.vecteezy.com/system/resources/thumbnails/004/607/791/small/man-face-emotive-icon-smiling-male-character-in-blue-shirt-flat-illustration-isolated-on-white-happy-human-psychological-portrait-positive-emotions-user-avatar-for-app-web-design-vector.jpg"
                  alt=""
                />
                <span>Sakib Hossen</span>
              </div>
              <img src="./download.png" className="icon" alt="" />
            </div>
            <div className="photoItem">
              <div className="photoDetails">
                <img
                  src="https://static.vecteezy.com/system/resources/thumbnails/004/607/791/small/man-face-emotive-icon-smiling-male-character-in-blue-shirt-flat-illustration-isolated-on-white-happy-human-psychological-portrait-positive-emotions-user-avatar-for-app-web-design-vector.jpg"
                  alt=""
                />
                <span>Sakib Hossen</span>
              </div>
              <img src="./download.png" className="icon" alt="" />
            </div>
            <div className="photoItem">
              <div className="photoDetails">
                <img
                  src="https://static.vecteezy.com/system/resources/thumbnails/004/607/791/small/man-face-emotive-icon-smiling-male-character-in-blue-shirt-flat-illustration-isolated-on-white-happy-human-psychological-portrait-positive-emotions-user-avatar-for-app-web-design-vector.jpg"
                  alt=""
                />
                <span>Sakib Hossen</span>
              </div>
              <img src="./download.png" className="icon" alt="" />
            </div>
            <div className="photoItem">
              <div className="photoDetails">
                <img
                  src="https://static.vecteezy.com/system/resources/thumbnails/004/607/791/small/man-face-emotive-icon-smiling-male-character-in-blue-shirt-flat-illustration-isolated-on-white-happy-human-psychological-portrait-positive-emotions-user-avatar-for-app-web-design-vector.jpg"
                  alt=""
                />
                <span>Sakib Hossen</span>
              </div>
              <img src="./download.png" className="icon" alt="" />
            </div>
          </div>
        </div>
        <div className="option">
          <div className="title">
            <span>Shared files</span>
            <img src="./arrowUp.png" alt="" />
          </div>
        </div>
        <button onClick={handleBlock}>
          {isCurrentUserBlocked ? "Unblock Now" : "Block User"}
        </button>
        <button className="logout" onClick={() => auth.signOut()}>
          Logout
        </button>
      </div>
    </div>
  );
};

export default Details;
