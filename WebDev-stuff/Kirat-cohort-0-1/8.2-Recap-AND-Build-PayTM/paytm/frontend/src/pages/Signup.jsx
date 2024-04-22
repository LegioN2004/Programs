import axios from "axios";
import { useState } from "react";
import { BottomWarning } from "../components/BottomWarning";
import { Button } from "../components/Button";
import { Heading } from "../components/Heading";
import { InputBox } from "../components/InputBox";
import { SubHeading } from "../components/Subheading";

import { useNavigate } from "react-router-dom";

export const Signup = () => {
  const [firstName, setFirstName] = useState("");
  const [lastName, setLastName] = useState("");
  const [username, setUsername] = useState("");
  const [password, setPassword] = useState("");
  const navigate = useNavigate();

  return (
    <>
      <div className="h-screen bg-slate-400 flex justify-center">
        <div className="bg-white w-80 m-9 p-5 mx-auto rounded-lg">
          <div className="text-center">
            <Heading label={"Sign Up"}></Heading>
            <SubHeading
              subheading={"Enter your information to create an account"}
            ></SubHeading>
          </div>
          <div className="text-left">
            <InputBox
              onChange={(e) => {
                setFirstName(e.target.value);
              }}
              label={"First Name"}
              placeholder={"Enter you name"}
            ></InputBox>
            <InputBox
              onChange={(e) => {
                setLastName(e.target.value);
              }}
              label={"Last Name"}
              placeholder={"Enter you last name"}
            ></InputBox>
            <InputBox
              onChange={(e) => {
                setUsername(e.target.value);
              }}
              label={"Email"}
              placeholder={"example johndoe@gmail.com"}
            ></InputBox>
            <InputBox
              onChange={(e) => {
                setPassword(e.target.value);
              }}
              label={"Password"}
              placeholder={"Enter you password"}
            ></InputBox>
          </div>
          <div className="text-left pt-3">
            <Button
              onClick={async () => {
                const response = await axios.post(
                  "http://localhost:3000/api/v1/user/signup",
                  {
                    username,
                    password,
                    firstName,
                    lastName,
                  },
                );
                localStorage.setItem("token", response.data.token);
              }}
              label={"Sign up"}
              to={"/signin"}
            ></Button>
          </div>
          <div className="text-left pt-3">
            <BottomWarning
              label={"Already have an account,"}
              buttonText={"Sign in"}
              to={"/signin"}
            ></BottomWarning>
          </div>
        </div>
      </div>
    </>
  );
};
