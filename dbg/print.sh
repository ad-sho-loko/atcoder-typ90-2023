# vector
template <typename T> ostream &operator<<(ostream &os, vector<T> &vec) {
    os << "{";
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}

# pair
template<typename T, typename U>
ostream& operator << (ostream& os, pair<T, U>& pair_var) {
	os << "(" << pair_var.first << ", " << pair_var.second << ")";
	return os;
}

# map
template<typename T, typename U>
ostream& operator << (ostream& os, map<T, U>& map_var) {
	os << "{";
	for (map<T, U>::iterator itr = map_var.begin(); itr != map_var.end(); itr++) {
		os << "(" << itr->first << ", " << itr->second << ")";
		itr++;
		if(itr != map_var.end()) os << ", ";
		itr--;
	}
	os << "}";
	return os;
}

# set
template<typename T>
ostream& operator << (ostream& os, set<T>& set_var) {
	os << "{";
	for (auto itr = set_var.begin(); itr != set_var.end(); itr++) {
		os << *itr;
		++itr;
		if(itr != set_var.end()) os << ", ";
		itr--;
	}
	os << "}";
	return os;
}