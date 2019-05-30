#include "project.hpp"

// Constructors & destructors
MindOpen::MindOpen( void ) : _memory(MindOpen::memory(NUMBER_OF_CHARS_IN_VECTOR, 0)) {}
MindOpen::MindOpen( MindOpen const & src ) { *this = src; }
MindOpen::~MindOpen( void )
{
	MindOpen::instructions_iterator	iit = this->_instructions.begin();
	while (iit != this->_instructions.end()) {
		delete *iit;
		iit++;
	}
}

// Operators override
MindOpen&	MindOpen::operator=( MindOpen const & ) { return *this; }

// Member function to open, read content and close filename
void				MindOpen::parse( std::string const filename )
{

	// Declare variables
	std::string			s;
	std::ifstream		ifs;
	std::stringstream	stream;

	// Open file
	ifs.open(filename);

	// Check if file opening worked
	if (!ifs.is_open())
		throw(std::runtime_error(std::strerror(errno)));

	// Read file
    stream << ifs.rdbuf();
	s = stream.str();

	// Close file
	ifs.close();

	// Parse file
	for ( unsigned long index = 0 ; s[index] != '\0' ; index++ )
		if (s[index] == INSTRUCTION_DECREMENT_BYTE) {
			AInstructions *instruction = new InstructionDecrementByte();
			this->_instructions.push_back(instruction);
		} else if (s[index] == INSTRUCTION_INCREMENT_BYTE) {
			AInstructions *instruction = new InstructionIncrementByte();
			this->_instructions.push_back(instruction);
		} else if (s[index] == INSTRUCTION_DECREMENT_POINTER) {
			AInstructions *instruction = new InstructionDecrementPointer();
			this->_instructions.push_back(instruction);
		} else if (s[index] == INSTRUCTION_INCREMENT_POINTER) {
			AInstructions *instruction = new InstructionIncrementPointer();
			this->_instructions.push_back(instruction);
		} else if (s[index] == INSTRUCTION_INPUT) {
			AInstructions *instruction = new InstructionInput();
			this->_instructions.push_back(instruction);
		} else if (s[index] == INSTRUCTION_OUTPUT) {
			AInstructions *instruction = new InstructionOutput();
			this->_instructions.push_back(instruction);
		} else if (s[index] == INSTRUCTION_JUMP_BACKWARD) {
			AInstructions *instruction = new InstructionJumpBackward();
			this->_instructions.push_back(instruction);
		} else if (s[index] == INSTRUCTION_JUMP_FORWARD) {
			AInstructions *instruction = new InstructionJumpForward();
			this->_instructions.push_back(instruction);
		}
}

// Member function to execute vector of instructions
void				MindOpen::execute( void ) {

	MindOpen::memory_iterator		mit = this->_memory.begin();
	MindOpen::memory_iterator		mit_beg = this->_memory.begin();
	MindOpen::memory_iterator		mit_end = this->_memory.end();

	MindOpen::instructions_iterator	iit = this->_instructions.begin();
	MindOpen::instructions_iterator iit_end = this->_instructions.end();

	while (iit != iit_end) {
		(*iit)->execute(mit, mit_beg, mit_end, iit);
		iit++;
	}
}
