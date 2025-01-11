import Container from 'react-bootstrap/Container';
import Navbar from 'react-bootstrap/Navbar';
import './App.css';
function BrandExample() {
  return (
    <>
      <Navbar className="bg-body-tertiary">
        <Container>
          <Navbar.Brand href="#home">
            <img
              src="https://th.bing.com/th?id=OIP.dJTqBQy3mMnMdI8klN_kHAHaGT&w=270&h=230&c=8&rs=1&qlt=90&o=6&dpr=1.3&pid=3.1&rm=2"
              width="30"
              height="30"
              className="d-inline-block align-top"
              alt="React Bootstrap logo"
            />
          </Navbar.Brand>
        </Container>
      </Navbar>
    
      <div style={{margin:"20px"}}><h1>Fun Facts about React</h1></div>
      <div>
      <ul>
        <li>Was First released in 2013</li>
        <li>Was originally created by Jordan Walke</li>
        <li>Has well over 100k starts on GitHub</li>
        <li>Is maintained by Meta</li>
        <li>Powers thousands of enterprise apps,inlcuding mobile apps</li>
      </ul>
      </div>
      
    </>
  );
}

export default BrandExample;
