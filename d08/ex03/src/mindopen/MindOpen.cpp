#include "project.hpp"

MindOpen::MindOpen(void) : _memory(MindOpen::memory(NUMBER_OF_CHARS_IN_VECTOR, 0)) {}
MindOpen::MindOpen(MindOpen const & src) { *this = src; }
MindOpen::~MindOpen(void)
{
	MindOpen::instructions_iterator	iit = this->_instructions.begin();
	while (iit != this->_instructions.end())
	{
		delete *iit;
		iit++;
	}
}
MindOpen&	MindOpen::operator=(MindOpen const &) { return *this; }

void				MindOpen::parse( std::string const filename )
{
	std::string			s;
	std::ifstream		ifs;
	std::stringstream	stream;

	// file read
	ifs.open(filename);
	if (!ifs.is_open())
		throw(std::runtime_error(std::strerror(errno)));
    stream << ifs.rdbuf();
	s = stream.str();
	ifs.close();

	// Parsing
	for (unsigned long i = 0 ; s[i] != '\0' ; i++)
		if (s[i] == INSTRUCTION_DECREMENT_BYTE) {
			AInstructions *instruction = new InstructionDecrementByte();
			this->_instructions.push_back(instruction);
		} else if (s[i] == INSTRUCTION_INCREMENT_BYTE) {
			AInstructions *instruction = new InstructionIncrementByte();
			this->_instructions.push_back(instruction);
		} else if (s[i] == INSTRUCTION_DECREMENT_POINTER) {
			AInstructions *instruction = new InstructionDecrementPointer();
			this->_instructions.push_back(instruction);
		} else if (s[i] == INSTRUCTION_INCREMENT_POINTER) {
			AInstructions *instruction = new InstructionIncrementPointer();
			this->_instructions.push_back(instruction);
		} else if (s[i] == INSTRUCTION_INPUT) {
			AInstructions *instruction = new InstructionInput();
			this->_instructions.push_back(instruction);
		} else if (s[i] == INSTRUCTION_OUTPUT) {
			AInstructions *instruction = new InstructionOutput();
			this->_instructions.push_back(instruction);
		} else if (s[i] == INSTRUCTION_JUMP_BACKWARD) {
			AInstructions *instruction = new InstructionJumpBackward();
			this->_instructions.push_back(instruction);
		} else if (s[i] == INSTRUCTION_JUMP_FORWARD) {
			AInstructions *instruction = new InstructionJumpForward();
			this->_instructions.push_back(instruction);
		}
}

void				MindOpen::execute( void ) {

	MindOpen::memory_iterator		mit = this->_memory.begin();
	MindOpen::memory_iterator		mit_beg = this->_memory.begin();
	MindOpen::memory_iterator		mit_end = this->_memory.end();

	MindOpen::instructions_iterator	iit = this->_instructions.begin();
	MindOpen::instructions_iterator iit_end = this->_instructions.end();

	while (iit != iit_end)
	{
		(*iit)->execute(mit, mit_beg, mit_end, iit);
		iit++;
	}
}
