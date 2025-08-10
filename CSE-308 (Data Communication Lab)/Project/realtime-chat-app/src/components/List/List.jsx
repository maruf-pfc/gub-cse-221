import Chatlist from "./Chatlist/Chatlist";
import "./List.css";
import UserInfo from "./UserInfo/UserInfo";

const List = () => {
  return (
    <div className="list">
      <UserInfo />
      <Chatlist />
    </div>
  );
};

export default List;
