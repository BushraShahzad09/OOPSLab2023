#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Point
{
public:
    double x, y;

    Point(double x, double y) : x(x), y(y) {}
};

class Cluster
{
public:
    Point centroid;
    vector<Point> points;

    Cluster(Point centroid) : centroid(centroid) {}

    void clearPoints()
    {
        points.clear();
    }
};

double distance(const Point &p1, const Point &p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int assignToCluster(const Point &point, const vector<Cluster> &clusters)
{
    int clusterIndex = 0;
    double minDistance = distance(point, clusters[0].centroid);

    for (size_t i = 1; i < clusters.size(); ++i)
    {
        double currentDistance = distance(point, clusters[i].centroid);
        if (currentDistance < minDistance)
        {
            minDistance = currentDistance;
            clusterIndex = static_cast<int>(i);
        }
    }

    return clusterIndex;
}

Point calculateCentroid(const vector<Point> &points)
{
    Point centroid(0.0, 0.0);
    for (const Point &point : points)
    {
        centroid.x += point.x;
        centroid.y += point.y;
    }

    centroid.x /= points.size();
    centroid.y /= points.size();

    return centroid;
}

void kMeans(vector<Point> &data, int k)
{
    srand(static_cast<unsigned int>(time(nullptr)));

    // Initialize clusters with random centroids
    vector<Cluster> clusters;
    for (int i = 0; i < k; ++i)
    {
        Point randomPoint(data[rand() % data.size()]);
        clusters.emplace_back(randomPoint);
    }

    const int maxIterations = 100;
    for (int iteration = 0; iteration < maxIterations; ++iteration)
    {
        // Assign points to clusters
        for (Cluster &cluster : clusters)
        {
            cluster.clearPoints();
        }

        for (const Point &point : data)
        {
            int clusterIndex = assignToCluster(point, clusters);
            clusters[clusterIndex].points.push_back(point);
        }

        // Update cluster centroids
        for (Cluster &cluster : clusters)
        {
            if (!cluster.points.empty())
            {
                cluster.centroid = calculateCentroid(cluster.points);
            }
        }
    }

    // Print the final clusters
    for (size_t i = 0; i < clusters.size(); ++i)
    {
        cout << "Cluster " << i + 1 << " - Centroid: (" << clusters[i].centroid.x << ", " << clusters[i].centroid.y << ")\n";
        cout << "Points in the cluster:\n";
        for (const Point &point : clusters[i].points)
        {
            cout << "(" << point.x << ", " << point.y << ") ";
        }
        cout << "\n\n";
    }
}

int main()
{
    const int dataSize = 500;
    vector<Point> data;

    // Generate random data points
    for (int i = 0; i < dataSize; ++i)
    {
        double x = static_cast<double>(rand()) / RAND_MAX * 100.0; // Random x in the range [0, 100)
        double y = static_cast<double>(rand()) / RAND_MAX * 100.0; // Random y in the range [0, 100)
        data.emplace_back(x, y);
    }

    int k = 3; // Number of clusters

    // Run k-Means algorithm
    kMeans(data, k);

    return 0;
}
