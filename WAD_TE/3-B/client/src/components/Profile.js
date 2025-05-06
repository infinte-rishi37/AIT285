import React, { useState, useEffect } from 'react';
import axios from 'axios';

function Profile() {
    const [user, setUser] = useState(null);
    const [name, setName] = useState('');
    const [email, setEmail] = useState('');

    useEffect(() => {
        const fetchUser = async () => {
            try {
                const userId = localStorage.getItem('userId');
                if (!userId) {
                    alert('No user ID found. Please log in.');
                    window.location = '/login';
                    return;
                }
                const res = await axios.get(`${process.env.REACT_APP_API_URL}/api/users/profile?userId=${userId}`);
                setUser(res.data);
                setName(res.data.name);
                setEmail(res.data.email);
            } catch (error) {
                alert(error.response?.data?.msg || 'Error fetching profile');
            }
        };
        fetchUser();
    }, []);

    const handleUpdate = async (e) => {
        e.preventDefault();
        try {
            const userId = localStorage.getItem('userId');
            const res = await axios.put(`${process.env.REACT_APP_API_URL}/api/users/profile`, {
                userId,
                name,
                email,
            });
            setUser(res.data);
            alert('Profile updated');
        } catch (error) {
            alert(error.response?.data?.msg || 'Error updating profile');
        }
    };

    const handleDelete = async () => {
        if (window.confirm('Are you sure you want to delete your account?')) {
            try {
                const userId = localStorage.getItem('userId');
                await axios.delete(`${process.env.REACT_APP_API_URL}/api/users/profile`, {
                    data: { userId },
                });
                localStorage.removeItem('userId');
                window.location = '/login';
            } catch (error) {
                alert(error.response?.data?.msg || 'Error deleting profile');
            }
        }
    };

    const handleLogout = () => {
        localStorage.removeItem('userId');
        window.location = '/login';
    };

    if (!user) return <div>Loading...</div>;

    return (
        <div className="profile-container">
            <h2>Profile</h2>
            <p>Name: {user.name}</p>
            <p>Email: {user.email}</p>
            <h3>Update Profile</h3>
            <form onSubmit={handleUpdate}>
                <input
                    type="text"
                    placeholder="Name"
                    value={name}
                    onChange={(e) => setName(e.target.value)}
                />
                <input
                    type="email"
                    placeholder="Email"
                    value={email}
                    onChange={(e) => setEmail(e.target.value)}
                />
                <button type="submit">Update</button>
            </form>
            <button className="delete-btn" onClick={handleDelete}>
                Delete Account
            </button>
            <button className="logout-btn" onClick={handleLogout}>
                Logout
            </button>
        </div>
    );
}

export default Profile;