const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const User = require('../models/User');

// Register User (Create)
router.post('/register', async (req, res) => {
    const { name, email, password } = req.body;
    try {
        let user = await User.findOne({ email });
        if (user) return res.status(400).json({ msg: 'User already exists' });

        user = new User({ name, email, password });
        await user.save();

        res.json({ userId: user.id });
    } catch (error) {
        res.status(500).json({ msg: 'Server error' });
    }
});

// Login User
router.post('/login', async (req, res) => {
    const { email, password } = req.body;
    try {
        const user = await User.findOne({ email });
        if (!user) return res.status(400).json({ msg: 'Invalid credentials' });

        const isMatch = await user.matchPassword(password);
        if (!user) return res.status(400).json({ msg: 'Invalid credentials' });

        res.json({ userId: user.id });
    } catch (error) {
        res.status(500).json({ msg: 'Server error' });
    }
});

// Get User Profile (Read)
router.get('/profile', async (req, res) => {
    const { userId } = req.query;
    try {
        const user = await User.findById(userId).select('-password');
        if (!user) return res.status(404).json({ msg: 'User not found' });
        res.json(user);
    } catch (error) {
        res.status(500).json({ msg: 'Server error' });
    }
});

// Update User (Update)
router.put('/profile', async (req, res) => {
    const { userId, name, email } = req.body;
    try {
        const user = await User.findById(userId);
        if (!user) return res.status(404).json({ msg: 'User not found' });

        user.name = name || user.name;
        user.email = email || user.email;
        await user.save();

        res.json(user);
    } catch (error) {
        res.status(500).json({ msg: 'Server error' });
    }
});

// Delete User (Delete)
router.delete('/profile', async (req, res) => {
    const { userId } = req.body;
    try {
        const user = await User.findByIdAndDelete(userId);
        if (!user) return res.status(404).json({ msg: 'User not found' });
        res.json({ msg: 'User deleted' });
    } catch (error) {
        res.status(500).json({ msg: 'Server error' });
    }
});

module.exports = router;