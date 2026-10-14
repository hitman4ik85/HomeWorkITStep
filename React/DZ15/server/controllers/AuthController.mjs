import User from "../models/User.mjs"
import bcrypt from "bcrypt"
import jwt from "jsonwebtoken"

export const register = async (req, res) => {
    try {
        const user = new User(req.body)
        await user.save()
        res.send(user)
    }
    catch (e) {
        res.status(400).send(e.message)
    }
}

export const login = async (req, res) => {
    try {
        const user = await User.findOne({ email: req.body.email })
        if (!user) {
            return res.status(400).send('User not found')
        }
        const validPassword = await bcrypt.compare(req.body.password, user.password)
        if (!validPassword) {
            return res.status(400).send('Invalid password')
        }
        const token = jwt.sign({ _id: user._id }, 'secret', { expiresIn: '1d' })
        res.send({ user, token })
    }
    catch (e) {
        res.status(400).send(e.message)
    }
}

export const getAuthUser = async (req, res) => {
    try {
        const user = await User.findById(req._id)
        res.send(user)
    }
    catch (e) {
        res.status(400).send(e.message)
    }
}

// функція редагування профілю (email, name, password)
export const updateProfile = async (req, res) => {
  try {
    const data = { ...req.body };
    if (data.password) {
      data.password = await bcrypt.hash(data.password, 10);
    }
    const user = await User.findByIdAndUpdate(req._id, data, { new: true });
    res.send(user);
  }
  catch (e) {
    res.status(400).send(e.message);
  }
}
