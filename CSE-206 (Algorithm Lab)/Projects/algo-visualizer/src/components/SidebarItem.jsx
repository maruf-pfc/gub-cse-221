import React from "react";

const SidebarItem = (name, path) => {
  return (
    <div>
      <a href={`/${path}`}>
        <List className="p-0 ">
          <ListItem className="text-white hover:text-yellow bg-sidebar hover:bg-sidebarHover">
            <ListItemPrefix>
              <ChevronRightIcon strokeWidth={3} className="h-3 w-5" />
            </ListItemPrefix>
            {name}
          </ListItem>
        </List>
      </a>
    </div>
  );
};

export default SidebarItem;
