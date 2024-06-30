#include <gtest/gtest.h>
#include "user.h"
#include "user_repository.h"
#include "user_service.h"

#include "user_not_found_exception.h"

// Testing User
TEST(UserTest, Getters) {
    User user("jimmy", "jimmy@gmail.com", "jimmy0000");
    EXPECT_EQ(user.getName(), "jimmy");
    EXPECT_EQ(user.getEmail(), "jimmy@gmail.com");
    EXPECT_EQ(user.getPwd(), "jimmy0000");
}

// Testing UserRepository
TEST(UserRepositoryTest, SaveAndRetrieveUser) {
    UserRepository repo;
    User *user = new User("jimmy", "jimmy@gmail.com", "jimmy0000");
    repo.saveUser(user);

    User *retrievedUser = repo.getUserByEmail("jimmy@gmail.com", "jimmy0000");
    ASSERT_NE(retrievedUser, nullptr);
    EXPECT_EQ(retrievedUser->getName(), "jimmy");

    delete retrievedUser;
}

// Testing UserService
TEST(UserServiceTest, SaveAndRetrieveUser) {
    UserRepository repo;
    UserService service(&repo);

    service.saveUser("hank", "hank@gmail.com", "hank1234");

    User *retrievedUser = service.getUserByEmail("hank@gmail.com", "hank1234");
    ASSERT_NE(retrievedUser, nullptr);
    EXPECT_EQ(retrievedUser->getName(), "hank");

    delete retrievedUser;
}

TEST(UserServiceTest, NonExistedUser) {
    UserRepository repo;
    UserService service(&repo);

    EXPECT_THROW({
        service.getUserByEmail("null@gmail.com", "null");
    }, UserNotFoundException);
}