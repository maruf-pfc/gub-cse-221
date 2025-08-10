import React from "react";

const Footer = () => {
  const year = new Date().getFullYear();
  return (
    <div className="text-center w-[85%] bottom-0 absolute my-2">
      &copy; {year} - All rights reserved by,{" "}
      <a className="text-crimson" href="https://www.youtube.com/@maruf_sarker" target="_blank">
        Md. Maruf Sarker
      </a>
    </div>
  );
};

export default Footer;
