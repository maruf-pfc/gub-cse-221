import React from "react";
import {
  Card,
  Typography,
  List,
  ListItem,
  ListItemPrefix,
  Accordion,
  AccordionHeader,
  AccordionBody,
} from "@material-tailwind/react";
import { FaFeatherAlt } from "react-icons/fa";
import { BiSearchAlt } from "react-icons/bi";
import { GiNetworkBars } from "react-icons/gi";
import { GrNodes } from "react-icons/gr";
import { IoIosArrowDown } from "react-icons/io";
import { Link } from "react-router-dom";

const Sidebar = () => {
  const [open, setOpen] = React.useState(0);

  const handleOpen = (value) => {
    setOpen(open === value ? 0 : value);
  };

  return (
    <div className="text-white">
      <Card className="bg-black text-white h-screen w-full max-w-[20rem] p-4 rounded-none font-body">
        <div className="mb-2 p-2">
          <Typography variant="h5">Algo Visualizer</Typography>
        </div>
        <List>
          <Accordion
            open={open === 1}
            icon={
              <IoIosArrowDown
                strokeWidth={2.5}
                className={`mx-auto h-4 w-4 transition-transform ${
                  open === 1 ? "rotate-180" : ""
                }`}
              />
            }
          >
            <ListItem className="p-0 hover:bg-black " selected={open === 3}>
              <AccordionHeader
                onClick={() => handleOpen(1)}
                className="p-3 bg-black  rounded-lg outline-none border-none w-full hover:bg-black Hover text-yellow hover:text-yellow"
              >
                <ListItemPrefix>
                  <BiSearchAlt className="h-5 w-5 text-yellow" />
                </ListItemPrefix>
                <Typography className="mr-auto font-normal text-white">
                  Searching Algorithms
                </Typography>
              </AccordionHeader>
            </ListItem>
            <Link to="/linear-search">
              <AccordionBody className="py-1">
                <List className="p-0 ">
                  <ListItem className="text-white hover:text-yellow bg-black  hover:bg-black Hover ">
                    <ListItemPrefix>
                      <FaFeatherAlt className="h-5 w-5" />
                    </ListItemPrefix>
                    Linear Search
                  </ListItem>
                </List>
              </AccordionBody>
            </Link>
            <Link to="/binary-search">
              <AccordionBody className="py-1">
                <List className="p-0">
                  <ListItem className="text-white hover:text-yellow bg-black  hover:bg-black Hover ">
                    <ListItemPrefix>
                      <FaFeatherAlt className="h-5 w-5" />
                    </ListItemPrefix>
                    Binary Search
                  </ListItem>
                </List>
              </AccordionBody>
            </Link>
          </Accordion>
          <Accordion
            open={open === 2}
            icon={
              <IoIosArrowDown
                strokeWidth={2.5}
                className={`mx-auto h-4 w-4 transition-transform ${
                  open === 2 ? "rotate-180" : ""
                }`}
              />
            }
          >
            <ListItem className="p-0 hover:bg-black " selected={open === 2}>
              <AccordionHeader
                onClick={() => handleOpen(2)}
                className="p-3 bg-black  rounded-lg outline-none border-none w-full hover:bg-black Hover text-yellow hover:text-yellow"
              >
                <ListItemPrefix>
                  <GiNetworkBars className="h-5 w-5 text-yellow" />
                </ListItemPrefix>
                <Typography className="mr-auto font-normal text-white">
                  Sorting Algorithms
                </Typography>
              </AccordionHeader>
            </ListItem>
            <Link to="/bubble-sort">
              <AccordionBody className="py-1">
                <List className="p-0 ">
                  <ListItem className="text-white hover:text-yellow bg-black  hover:bg-black Hover ">
                    <ListItemPrefix>
                      <FaFeatherAlt className="h-5 w-5" />
                    </ListItemPrefix>
                    Bubble Sort
                  </ListItem>
                </List>
              </AccordionBody>
            </Link>
            <Link to="/counting-sort">
              <AccordionBody className="py-1">
                <List className="p-0 ">
                  <ListItem className="text-white hover:text-yellow bg-black  hover:bg-black Hover ">
                    <ListItemPrefix>
                      <FaFeatherAlt className="h-5 w-5" />
                    </ListItemPrefix>
                    Counting Sort
                  </ListItem>
                </List>
              </AccordionBody>
            </Link>
            <Link to="/heap-sort">
              <AccordionBody className="py-1">
                <List className="p-0 ">
                  <ListItem className="text-white hover:text-yellow bg-black  hover:bg-black Hover ">
                    <ListItemPrefix>
                      <FaFeatherAlt className="h-5 w-5" />
                    </ListItemPrefix>
                    Heap Sort
                  </ListItem>
                </List>
              </AccordionBody>
            </Link>
            <Link to="/insertion-sort">
              <AccordionBody className="py-1">
                <List className="p-0 ">
                  <ListItem className="text-white hover:text-yellow bg-black  hover:bg-black Hover ">
                    <ListItemPrefix>
                      <FaFeatherAlt className="h-5 w-5" />
                    </ListItemPrefix>
                    Insertion Sort
                  </ListItem>
                </List>
              </AccordionBody>
            </Link>
            <Link to="/merge-sort">
              <AccordionBody className="py-1">
                <List className="p-0 ">
                  <ListItem className="text-white hover:text-yellow bg-black  hover:bg-black Hover ">
                    <ListItemPrefix>
                      <FaFeatherAlt className="h-5 w-5" />
                    </ListItemPrefix>
                    Merge Sort
                  </ListItem>
                </List>
              </AccordionBody>
            </Link>
            <Link to="/quick-sort">
              <AccordionBody className="py-1">
                <List className="p-0 ">
                  <ListItem className="text-white hover:text-yellow bg-black  hover:bg-black Hover ">
                    <ListItemPrefix>
                      <FaFeatherAlt className="h-5 w-5" />
                    </ListItemPrefix>
                    Quick Sort
                  </ListItem>
                </List>
              </AccordionBody>
            </Link>
            <Link to="/radix-sort">
              <AccordionBody className="py-1">
                <List className="p-0 ">
                  <ListItem className="text-white hover:text-yellow bg-black  hover:bg-black Hover ">
                    <ListItemPrefix>
                      <FaFeatherAlt className="h-5 w-5" />
                    </ListItemPrefix>
                    Radix Sort
                  </ListItem>
                </List>
              </AccordionBody>
            </Link>
            <Link to="/selection-sort">
              <AccordionBody className="py-1">
                <List className="p-0 ">
                  <ListItem className="text-white hover:text-yellow bg-black  hover:bg-black Hover ">
                    <ListItemPrefix>
                      <FaFeatherAlt className="h-5 w-5" />
                    </ListItemPrefix>
                    Selection Sort
                  </ListItem>
                </List>
              </AccordionBody>
            </Link>
          </Accordion>
          <Accordion
            open={open === 3}
            icon={
              <IoIosArrowDown
                strokeWidth={2.5}
                className={`mx-auto h-4 w-4 transition-transform ${
                  open === 3 ? "rotate-180" : ""
                }`}
              />
            }
          >
            <ListItem className="p-0 hover:bg-black " selected={open === 3}>
              <AccordionHeader
                onClick={() => handleOpen(3)}
                className="p-3 bg-black  rounded-lg outline-none border-none w-full hover:bg-black Hover text-yellow hover:text-yellow"
              >
                <ListItemPrefix>
                  <GrNodes className="h-5 w-5 bg-yellow rounded-full p-[0.9px]" />
                </ListItemPrefix>
                <Typography className="mr-auto font-normal text-white">
                  Graph
                </Typography>
              </AccordionHeader>
            </ListItem>
            <Link to="/bfs-search">
              <AccordionBody className="py-1">
                <List className="p-0 ">
                  <ListItem className="text-white hover:text-yellow bg-black  hover:bg-black Hover ">
                    <ListItemPrefix>
                      <FaFeatherAlt className="h-5 w-5" />
                    </ListItemPrefix>
                    BFS Search
                  </ListItem>
                </List>
              </AccordionBody>
            </Link>
            <Link to="/dfs-search">
              <AccordionBody className="py-1">
                <List className="p-0 ">
                  <ListItem className="text-white hover:text-yellow bg-black  hover:bg-black Hover ">
                    <ListItemPrefix>
                      <FaFeatherAlt className="h-5 w-5" />
                    </ListItemPrefix>
                    DFS Search
                  </ListItem>
                </List>
              </AccordionBody>
            </Link>
            <Link to="/dijkstra">
              <AccordionBody className="py-1">
                <List className="p-0 ">
                  <ListItem className="text-white hover:text-yellow bg-black  hover:bg-black Hover ">
                    <ListItemPrefix>
                      <FaFeatherAlt className="h-5 w-5" />
                    </ListItemPrefix>
                    Dijkstra
                  </ListItem>
                </List>
              </AccordionBody>
            </Link>
          </Accordion>
          {/* <ListItem className="text-white hover:text-yellow bg-black  hover:bg-black Hover ">
            <ListItemPrefix>
              <Cog6ToothIcon className="h-7 w-7 text-yellow rounded-full p-1" />
            </ListItemPrefix>
            Settings
          </ListItem> */}
        </List>
      </Card>
    </div>
  );
};

export default Sidebar;
