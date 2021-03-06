unsigned int InstallCallHook(unsigned int callAddress, unsigned int targetFunction)
{
	unsigned int originalTarget = (callAddress + 5) + *(int*)(callAddress + 1);

	int targetOffset = targetFunction - (callAddress + 5);
	*(unsigned char*)callAddress = 0xE8;
	*(unsigned int*)(callAddress + 1) = targetOffset;

	return originalTarget;
}

unsigned int InstallJumpHook(unsigned int callAddress, unsigned int targetFunction)
{
	unsigned int originalTarget = (callAddress + 5) + *(int*)(callAddress + 1);

	int targetOffset = targetFunction - (callAddress + 5);
	*(unsigned char*)callAddress = 0xE9;
	*(unsigned int*)(callAddress + 1) = targetOffset;

	return originalTarget;
}