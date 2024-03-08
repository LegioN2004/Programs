const jwt = require("jsonwebtoken");
const {JWT_SECRET} = require( "../dbConfig");
const zod = require("zod");
const {User} = require("../db");
const userSchema = zod.object({
    userName: zod.string().min(3).max(30).email(),
    firstName: zod.string().max(50),
    lastName: zod.string().max(50),
    password: zod.string().min(6),
});

const userId = Math.floor(Math.random() * 1000000);

async function signupMiddleware(req, res, next) {
    const userName = req.body.userName;
    const firstName = req.body.firstName;
    const lastName = req.body.lastName;
    const password = req.body.password;

    const parsedUsers = userSchema.safeParse({
        userName: req.body.userName,
        firstName: req.body.firstName,
        lastName: req.body.lastName,
        password: req.body.password,
    });

    const userExists = await User.findOne({
        userName: req.body.userName,
    });

    // credential logic
    try {
        if (!userExists && parsedUsers.success) {
            const user = new User({
                userName: userName,
                firstName: firstName,
                lastName: lastName,
                password: password,
                userId: userId,
            });
            await user.save();
            next();
        } else {
            res.status(411).json({
                msg: 'Username or password already exists, change your credentials',
            });
        }
    } catch (error) {
        res.status(500).json({
            msg: 'server errorrrrrrrrrrrrrr, refressssssssshhhhhhhhhhhhhhhh',
        });
    }
}
async function signinMiddleware(req, res, next) {
    const token = req.headers.authorization;
    const userExists = await User.findOne({
        userName: userSchema.safeParse(req.body.userName),
        password: userSchema.safeParse(req.body.password),
    });
    if(!token && !token.startsWith("Bearer ")){
        return res.status(403).json({msg:"invalid token",})
    }
    const tokenArray = token.split(" ")[1];
    const verification =  await jwt.verify(tokenArray, JWT_SECRET)

    // credential logic
    try {
        if (!userExists) {
            res.status(411).json({
                msg: 'error while logging in, wrong credentials, change em or if user not signed up, sign up first',
            });
        } else if(!verification){
            return res.status(403).json({
                message:
                    "Forbidden: Invalid token, or token doesn't exist get a new one by signing up :)",
            });
        }else{
            req.userId = tokenArray.userId;
            return tokenArray[1];
            next();
        }
    } catch (error) {
        res.status(500).json({
            msg: 'server errorrrrrrrrrrrrrr, refressssssssshhhhhhhhhhhhhhhh',
        });
    }
    next();
}
async function updateMiddleware(req, res, next) {
    const updatedBody = zod.object({
        firstName: zod.string().optional(),
        lastName: zod.string().optional(),
        password: zod.string().optional(),
    })

    const {success} = updatedBody.safeParse(req.body);
    try {
        if(!success){
            res.status(411).json({
                message: "Error while updating information"
            })
        }
        await User.updateOne({_id: req.userId}, req.body)
        next();
    } catch (error) {
        res.status(500).json({
            msg: 'server errorrrrrrrrrrrrrr, refressssssssshhhhhhhhhhhhhhhh',
        });
    }
}

module.exports = {
    signupMiddleware, signinMiddleware, updateMiddleware
}