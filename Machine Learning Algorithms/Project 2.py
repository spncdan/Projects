
# For my Project 2 I simply inputted the Pre-Made Data Handler Class, Naive Bayes Classifier, and Main(), afterwards I added the K-Nearest Neighbor Classifier and made enhancements to the main() in order to accommodate KNN.
# ChatGPT helped for error checking and answered questions when I asked how I could go about making my code more efficient or general questions on steps I could take towards finishing the KNN classifier and implementing the SVM algorithm.

import math
import csv
from random import shuffle
from math import sqrt # Sourced from ChatGPT
from collections import Counter # Sourced from ChatGPT

# Data Handler Class
# imported from pre made code by professor
class DataHandler:
    def __init__(self, filepath):
        # Constructor to initialize the filepath
        self.filepath = filepath

    def read_csv(self):
        # Read data from a CSV file and store it in a list
        with open(self.filepath, 'r') as file:
            csv_reader = csv.reader(file)
            next(csv_reader)  # Skip the header row
            dataset = [row for row in csv_reader]
        return dataset

    def train_test_split(self, dataset, test_size=0.2):
        # Shuffle the dataset to ensure randomness
        shuffle(dataset)
        # Determine the split index based on the test size
        split_index = int(len(dataset) * (1 - test_size))
        # Split the dataset into training and testing sets
        return dataset[:split_index], dataset[split_index:]

    def separate_features_labels(self, dataset):
        # Separate the features and labels from the dataset
        # Convert the feature values to floats for computation
        features = [list(map(float, data[1:-1])) for data in dataset]  # Exclude the ID and label
        labels = [data[-1] for data in dataset]  # The label is the last element in each row
        return features, labels

# Naive Bayes Classifier
# imported from pre made code by professor
class NaiveBayesClassifier:
    def __init__(self):
        # Initialize dictionaries to store the means, standard deviations,
        # and class probabilities for each class
        self.means = {}
        self.stds = {}
        self.class_probabilities = {}

    def fit(self, X, y):
        # Train the classifier by calculating the class probabilities
        # and the means and standard deviations for each feature
        self._calculate_class_probabilities(y)
        self._calculate_means_stds(X, y)

    def _calculate_class_probabilities(self, y):
        # Calculate the probability of each class based on label frequency
        class_counts = {label: y.count(label) for label in set(y)}
        total_count = len(y)
        self.class_probabilities = {label: count / total_count for label, count in class_counts.items()}

    def _calculate_means_stds(self, X, y):
        # Calculate the mean and standard deviation for each class and each feature
        for label in self.class_probabilities:
            # Extract features for instances of the current class
            label_features = [X[i] for i in range(len(X)) if y[i] == label]
            # Calculate mean and standard deviation for each feature
            self.means[label] = [sum(f) / len(f) for f in zip(*label_features)]
            self.stds[label] = [math.sqrt(sum([(x - mean)**2 for x in f]) / len(f)) for mean, f in zip(self.means[label], zip(*label_features))]

    def predict_single(self, input_features):
        # Predict the class of a single feature set
        probabilities = {}
        for label, _ in self.means.items():
            # Start with the prior probability of the class
            probabilities[label] = self.class_probabilities[label]
            # Multiply by the probability of each feature
            for i, feature in enumerate(input_features):
                probabilities[label] *= self._calculate_probability(feature, self.means[label][i], self.stds[label][i])
        # Return the class with the highest probability
        return max(probabilities, key=probabilities.get)

    def _calculate_probability(self, x, mean, std):
        # Calculate the probability of a feature value with a Gaussian distribution
        exponent = math.exp(-(math.pow(x-mean,2)/(2*math.pow(std,2))))
        return (1 / (math.sqrt(2*math.pi) * std)) * exponent

    def predict(self, X):
        # Predict a list of feature sets
        return [self.predict_single(features) for features in X]

    def classification_report(self, y_true, y_pred):
        # Generate a classification report for the predictions
        unique_labels = set(y_true)
        report = {}
        for label in unique_labels:
            tp = sum(1 for i in range(len(y_true)) if y_true[i] == label and y_pred[i] == label)
            fp = sum(1 for i in range(len(y_true)) if y_true[i] != label and y_pred[i] == label)
            fn = sum(1 for i in range(len(y_true)) if y_true[i] == label and y_pred[i] != label)
            tn = sum(1 for i in range(len(y_true)) if y_true[i] != label and y_pred[i] != label)

            # Calculate precision, recall, and F1-score for each class
            precision = tp / (tp + fp) if tp + fp > 0 else 0
            recall = tp / (tp + fn) if tp + fn > 0 else 0
            f1 = 2 * (precision * recall) / (precision + recall) if precision + recall > 0 else 0
            accuracy = (tp + tn) / len(y_true)

            report[label] = {
                'Precision': precision,
                'Recall': recall,
                'F1-score': f1,
                'Accuracy': accuracy
            }

        return report

# K-Nearest Neighbor Algorithm Classifier
# This algorithm will be used to classify by finding the closest data points in the training dataset to a new data point and predicting the label based on these nearest neighbors.
class KNNClassifier:
    def __init__(self, k=3): # k = 3 is the ideal k value as it is closer and gives a more concentrated value
        # Initialize the KNN classifier with a specified number of neighbors (k).
        self.k = k
        self.X_train = None
        self.y_train = None

    def fit(self, X_train, y_train):
        # Store the training dataset and corresponding labels.
        # This method does not do any actual computations because KNN is a lazy learner.
        self.X_train = X_train
        self.y_train = y_train

    def predict(self, X_test):
        # Predict the labels for a list of test data.
        predictions = []
        for x in X_test:
            # Predict the label for each test example and store the result.
            predictions.append(self._predict(x))
        return predictions

    def _predict(self, x):
        # Predict the label for a single test example using the k-nearest neighbor algorithm.
        distances = []
        for x_train in self.X_train:
            # Compute the Euclidean distance from the test example to each training example.
            # A Euclidean distance is the distance between two points is the length of the line segment between them. (Sourced from ChatGPT)
            distance = sqrt(sum([(x_train[i] - x[i]) ** 2 for i in range(len(x))]))
            distances.append(distance)
        
        # Pair each training example with its corresponding distance to the test example.
        # Sort these pairs based on the distance.
        k_nearest_neighbors = sorted((dist, label) for dist, label in zip(distances, self.y_train))[:self.k]
        
        # From the sorted list of pairs, extract the labels of the k nearest neighbors.
        # Use a Counter to count the occurrences of each class/label among the k-neighbors.
        most_common = Counter(label for _, label in k_nearest_neighbors).most_common(1)
        # The most common class label is considered the prediction for the test example.
        return most_common[0][0]

    def accuracy(self, y_true, y_pred):
        # Calculate the accuracy of the predictions.
        # Accuracy is defined as the proportion of correct predictions.
        correct = sum(1 for true, pred in zip(y_true, y_pred) if true == pred)
        return correct / len(y_true)  # Number of correct predictions divided by the total number of predictions.
    
# imported from pre made code by professor until the part where I implement the K-Nearest Neighbor's results
def main():
    # Define the path to the CSV file containing the Iris dataset
    filepath = 'C:/Users/Daniel/Desktop/Machine Learning Algorithms/iris.csv'

    # Initialize the data handler with the filepath
    # This object will handle all data operations
    data_handler = DataHandler(filepath)

    # Read the dataset from the CSV file using the read_csv method
    # The dataset is returned as a list of lists, where each sublist is a row from the file
    dataset = data_handler.read_csv()

    # Split the dataset into training and testing parts using the train_test_split method
    # Default split is 80% training and 20% testing
    train_set, test_set = data_handler.train_test_split(dataset)

    # Separate features and labels for the training set
    # train_features will contain the data attributes, and train_labels will contain the target labels
    train_features, train_labels = data_handler.separate_features_labels(train_set)

    # Separate features and labels for the testing set
    # This setup mirrors the training separation
    test_features, test_labels = data_handler.separate_features_labels(test_set)

    # Initialize the Naive Bayes Classifier
    # This object will perform all classification tasks
    classifier = NaiveBayesClassifier()

    # Fit the classifier on the training data
    # This process involves calculating necessary statistical parameters for the Naive Bayes algorithm
    classifier.fit(train_features, train_labels)

    # Predict the class labels for the test set features
    # The predict method uses the trained model to estimate the labels of unseen data
    predictions = classifier.predict(test_features)

    # Generate a classification report comparing the true labels and predicted labels
    # This report includes precision, recall, F1-score, and accuracy for each class
    report = classifier.classification_report(test_labels, predictions)

    # Print out the classification report for each class
    print("Naives Bayes Algorithm")
    print("Classification Report:")
    for label, metrics in report.items():
        print(f"Class {label}:")
        for metric, value in metrics.items():
            print(f"  {metric}: {value:.2f}")
        print()

    # Initialize the K-Nearest Neighbors Classifier with k neighbors
    # This object will perform all classification tasks
    k = 3  # Define the number of neighbors, k is a good concentrated number which may give us good results.
    classifier = KNNClassifier(k)

    # Fit the classifier on the training data
    classifier.fit(train_features, train_labels)

    # Predict the class labels for the test set features
    # The predict method uses the trained model to estimate the labels of unseen data
    predictions = classifier.predict(test_features)

    # Calculate the accuracy of the predictions
    accuracy = classifier.accuracy(test_labels, predictions)

    # Print out the accuracy and the predicted labels
    print("K-Nearest Neighbor")
    print("Predicted Labels:", predictions)
    print(f"Accuracy: {accuracy:.2f}")

# This block checks if this script is the main program and runs the main function
if __name__ == "__main__":
    main()
