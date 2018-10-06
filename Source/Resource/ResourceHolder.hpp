#ifndef GAME_RESOURCEHOLDER_HPP
#define GAME_RESOURCEHOLDER_HPP

#include <utility>
#include <unordered_map>
#include <memory>

/**
 * Contains a map with all requested resources
 * @tparam T Works only with classes from SFML like sf::Texture
 */
template<class T>
class ResourceHolder {
public:
	/**
	 * Constructs a new ResourceHolder
	 * @param folder  The folder path with an ending "/"
	 * @param extensions The file extension for example ".png"
	 * @param throwErrorIfUnknownCantBeFound If true an exception will be thrown if the requested resource doesn't exists at the given path and the unknown.{extension} can't be loaded
	 */
	ResourceHolder(std::string folder, std::string extensions, bool throwErrorIfUnknownCantBeFound = true) : m_folder(
			std::move(folder)), m_extension(std::move(extensions)), m_throwErrorIfUnknownCantBeFound(
			throwErrorIfUnknownCantBeFound) {}

	/**
	 * Remove the resource from the map
	 * @param name The name given at the get() function
	 */
	void removeResource(const std::string &name) {
		m_resources.erase(name);
	}

	/**
	 * Looks if the resource is already cached and if not, it load it and caches it
	 * @param name The name which will be the key in the map
	 * @return The reference of the resource
	 */
	const T &get(const std::string &name) {
		if (m_resources.find(name) == m_resources.end()) {
			addResource(name);
		}

		return m_resources[name];
	}


private:
	bool m_throwErrorIfUnknownCantBeFound;
	std::string m_folder, m_extension;
	std::unordered_map<std::string, T> m_resources;


	std::string getString(const std::string &filename, const std::string &folder, const std::string &extension) {
		return folder + filename + extension;
	}

	void addResource(std::string name) {
		T t;
		if (!t.loadFromFile(getString(name, m_folder, m_extension))) {
			if (!t.loadFromFile(getString("unknown", m_folder, m_extension))) {
				if (m_throwErrorIfUnknownCantBeFound) {
					throw std::runtime_error(
							"Failed to load " + name + " which led to load unknown but unknown doesn't exist!");
				}
			}
		}
		m_resources.emplace(name, t);
	}
};

#endif //GAME_RESOURCEHOLDER_HPP
