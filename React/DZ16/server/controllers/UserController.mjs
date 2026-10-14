import User from "../models/User.mjs";

// GET /users  (admin)
export const getUsers = async (req, res) => {
    try {
        const users = await User.find({}, { password: 0 }).sort({ createdAt: -1 });
        res.send(users);
    } catch (e) {
        res.status(400).send(e.message);
    }
};

// PUT /users/:id  (admin) — базове оновлення профілю (name/email)
export const updateUser = async (req, res) => {
    try {
        const { name, email } = req.body;
        const updated = await User.findByIdAndUpdate(
            req.params.id,
            { name, email },
            { new: true, projection: { password: 0 } }
        );
        res.send(updated);
    } catch (e) {
        res.status(400).send(e.message);
    }
};

// PUT /users/:id/role  (admin) — зміна ролі (user/admin)
export const setUserRole = async (req, res) => {
    try {
        const { role } = req.body; // 'admin' | 'user'
        if (!['admin', 'user'].includes(role)) {
            return res.status(400).send('Invalid role');
        }
        const updated = await User.findByIdAndUpdate(
            req.params.id,
            { role },
            { new: true, projection: { password: 0 } }
        );
        res.send(updated);
    } catch (e) {
        res.status(400).send(e.message);
    }
};

// DELETE /users/:id  (admin)
export const deleteUser = async (req, res) => {
    try {
        const deleted = await User.findByIdAndDelete(req.params.id);
        res.send(deleted);
    } catch (e) {
        res.status(404).send(e.message);
    }
};
