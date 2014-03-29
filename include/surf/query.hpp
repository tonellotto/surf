
#ifndef SURF_QUERY_HPP
#define SURF_QUERY_HPP

#include <vector>

namespace surf {

struct doc_score {
	uint64_t doc_id;
	double score;
    bool operator>(const doc_score& rhs) const {
    	if(score == rhs.score)
    		return doc_id > rhs.doc_id;
        return score > rhs.score;
    }
    doc_score() {};
    doc_score(uint64_t did,double s) : doc_id(did) , score(s) {};
};

struct result {
    std::vector<doc_score> list;
    uint64_t wt_search_space = 0;
    uint64_t wt_nodes = 0;
    uint64_t postings_evaluated = 0;
    uint64_t postings_total = 0;
};

struct query_token{
	uint64_t token_id;
	uint64_t f_qt;
	query_token(uint64_t id,uint64_t f) : token_id(id), f_qt(f) {}
};

using query_t = std::tuple<uint64_t,std::vector<query_token>,std::vector<std::string>>;


}

#endif