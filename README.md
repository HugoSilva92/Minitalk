# Grade 125/125

This project was the inicialization of bytes, process id's and signals.

The job was to have a "Client" and a "Server" that could could communicate through
signals (we could only use SIGUSR1 and SIGUSR2).

So the client received the pid of the server and sended an string as message.

The string was sended by bits, the SIGUSR1 was the 1 and SIGUSR2 the 0.

Then the server had to receive them and translate again to string.

The bonus of this project was to the server write a message that the string from the client was received.

Was an interesting project as I've gained a lot of knowledge about signals.

Subject of the project included on repository.
