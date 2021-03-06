bool comparex(const Point &a, const Point &b) {
    return sgn(a.x - b.x) < 0;
}

bool comparey(const Point &a, const Point &b) {
    return sgn(a.y - b.y) < 0;
}

double solve(const std::vector<Point> &point, int left, int right) {
    if (left == right) {
        return INF;
    }
    if (left + 1 == right) {
        return dist(point[left], point[right]);
    }
    int mid = left + right >> 1;
    double result = std::min(solve(left, mid), solve(mid + 1, right));
    std::vector<Point> candidate;
    for (int i = left; i <= right; ++i) {
        if (std::abs(point[i].x - point[mid].x) <= result) {
            candidate.push_back(point[i]);
        }
    }
    std::sort(candidate.begin(), candidate.end(), comparey);
    for (int i = 0; i < (int)candidate.size(); ++i) {
        for (int j = i + 1; j < (int)candidate.size(); ++j) {
            if (std::abs(candidate[i].y - candidate[j].y) >= result) {
                break;
            }
            result = std::min(result, dist(candidate[i], candidate[j]));
        }
    }
    return result;
}

double solve(std::vector<Point> point) {
    std::sort(point.begin(), point.end(), comparex);
    return solve(point, 0, (int)point.size() - 1);
}