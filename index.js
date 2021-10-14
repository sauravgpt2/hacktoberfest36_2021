const express = require("express");
const mongoose = require("mongoose");
const blogRouter = require("./routes/blog")
require("dotenv").config();

const localURL = "mongodb://localhost:27017/blog"

mongoose
  .connect(
    localURL,
    {
      useNewUrlParser: true,
      useUnifiedTopology: true,
    }
  )
  .then(() => console.log("conn succesful"))
  .catch((err) => console.log(err));

const app = express();
const methodOverride = require("method-override");
const path = require("path");


app.set("view engine", "ejs");
app.use("/blog",blogRouter)
app.use(express.urlencoded({ extended: true }));
app.use(methodOverride("_method"));
app.use(express.static(path.join(__dirname, "/public")));

app.get("/", (req, res) => {
  res.send("<a href='/blog'>Here </a>");
});

app.get("/hey", (req, res) => {
  res.send("hey");
});



app.listen(process.env.PORT || 3000, () => {
  console.log("server is running at port 3000");
  console.log("go to localhost:3000/blog");
});
