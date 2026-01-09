#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>

// The Observer Pattern is a behavioral design pattern that lets you define a subscription mechanism to notify multiple objects about any events that happen to the object they're observing.
// It defines a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.

// below example explained:
//  Subscriber (Observer) is the interface for objects that receive notifications.
//  YoutubeChannel (Subject) allows subscribers to join/leave and notifies them of new videos.
//  Example usage:
//  YoutubeChannel myChannel("TechTalks");
//  auto sub1 = std::make_shared<UserSubscriber>("Alice");
//  myChannel.subscribe(sub1);
//  myChannel.uploadVideo("C++ Design Patterns");
//  Output: Alice received notification: New Video Uploaded - C++ Design Patterns

// Step 1: Observer Interface
class Subscriber {
public:
    virtual void update(const std::string& videoTitle) = 0;
    virtual ~Subscriber() = default;
};

// Step 2: Concrete Observer
class UserSubscriber : public Subscriber {
private:
    std::string name;

public:
    UserSubscriber(std::string n) : name(n) {}

    void update(const std::string& videoTitle) override {
        std::cout << name << " received notification: New Video Uploaded - " << videoTitle << std::endl;
    }
};

// Step 3: Subject (Publisher)
class YoutubeChannel {
private:
    std::vector<std::shared_ptr<Subscriber>> subscribers;
    std::string channelName;

public:
    YoutubeChannel(std::string name) : channelName(name) {}

    void subscribe(std::shared_ptr<Subscriber> sub) {
        subscribers.push_back(sub);
    }

    void unsubscribe(std::shared_ptr<Subscriber> sub) {
        // Remove subscriber (requires comparison logic, simpler here to iterate)
        subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), sub), subscribers.end());
    }

    void uploadVideo(std::string title) {
        std::cout << "Channel " << channelName << " is uploading: " << title << std::endl;
        notifySubscribers(title);
    }

    void notifySubscribers(std::string title) {
        for (const auto& sub : subscribers) {
            sub->update(title);
        }
    }
};
