#include "BitmapStore.h"
#include <assert.h>
using namespace sf;
using namespace std;
BitmapStore* BitmapStore::m_s_Instance = nullptr;
BitmapStore::BitmapStore()
{
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}
void BitmapStore::addBitmap(std::string const& filename)
{
	//get a reference to m_Textures using m_s_Instance
	auto& bitmapsMap = m_s_Instance->m_BitmapsMap;
	auto keyValuePair = bitmapsMap.find(filename);
	//no match found
	if (keyValuePair == bitmapsMap.end())
	{
		//create new key value paid
		auto& texture = bitmapsMap[filename];
		//loat the texture from file the normal way
		texture.loadFromFile(filename);
	}
}
sf::Texture& BitmapStore::getBitmap(std::string const& filename)
{
	auto& m = m_s_Instance->m_BitmapsMap;
	auto keyValuePair = m.find(filename);
	if (keyValuePair != m.end()) return keyValuePair->second;
	else
	{
#ifdef debuggingOnConsole
		cout << "BitmapStore::getBitmap()Texture not found CRASH!" << end;
#endif
		return keyValuePair->second;
	}
}